/* 
 * File:   Server.cpp
 * Author: david
 * 
 * Created on September 15, 2015, 7:30 PM
 */

#include <pthread.h>
#include <string>

#include "Server.h"

Server::Server(int port) : Observable() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
    }

    memset((char *) &serv_addr, '\0', sizeof (serv_addr));

    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_family = AF_INET;

    if (bind(serverSocket, const_cast<sockaddr*> ((sockaddr *) & serv_addr),
            sizeof (serv_addr)) == -1) {
    }

    if (listen(serverSocket, 5) == -1) {
    }

    pthread_mutex_init(&clientsMutex, NULL);

    highestFD = serverSocket;

    running = true;

    FD_ZERO(&clientsFDs);

}

bool Server::isRunning() {
    return running;
}

void Server::sendMessage(char* ID, std::string message) {
    pthread_mutex_lock(&clientsMutex);

    for (std::vector<client>::iterator iterator = clients.begin();
            iterator != clients.end(); ++iterator) {
        if((*iterator).ID == ID){
            send((*iterator).fileDescriptor, message.data(), message.length(), NULL);
            break;
        }
    }

    pthread_mutex_unlock(&clientsMutex);
}

Server::~Server() {
    this->~Observable();
}

void * Server::clientsHandler(void* param) {
    Server * server = (Server *) param;

    fd_set readSet;

    timeval timeValue;

    FD_ZERO(&readSet);
    FD_SET(server->serverSocket, &readSet);

    while (server->running) {

        timeValue.tv_sec = 5;
        timeValue.tv_usec = 0;


        int * newClientFD = new int;

        if (select(server->serverSocket + 1, &readSet, NULL, NULL, &timeValue)
                == -1) {

        } else {
            if (FD_ISSET(server->serverSocket, &readSet)) {
                if ((*newClientFD = accept(server->serverSocket, NULL, NULL))
                        == -1) {
                } else {

                    client * newClient = new client;

                    char * IDbuffer = new char[11];

                    while (recv(*newClientFD, IDbuffer, 11, MSG_WAITALL) != -1)
                        ;

                    newClient->ID = IDbuffer;
                    newClient->fileDescriptor = *newClientFD;

                    pthread_mutex_lock(&server->clientsMutex);

                    server->clients.push_back(*newClient);

                    if (*newClientFD > server->highestFD) {
                        server->highestFD = *newClientFD;
                    }

                    pthread_mutex_unlock(&server->clientsMutex);
                }
            }
        }
    }
}

void * Server::ioHandler(void* param) {
    Server * server = (Server *) param;

    fd_set readSet;

    timeval timeValue;

    while (server->running) {
        FD_ZERO(&readSet);
        FD_SET(0, &readSet);

        timeValue.tv_sec = 5;
        timeValue.tv_usec = 0;

        if (select(server->highestFD + 1, &server->clientsFDs, NULL, NULL, &timeValue)
                == -1) {

        } else {
            char * msgBuffer;
            client cliente;
            pthread_mutex_lock(&server->clientsMutex);
            for (std::vector<client>::iterator iterator = server->clients.begin();
                    iterator != server->clients.end(); ++iterator) {
                cliente = *iterator;
                if (FD_ISSET(cliente.fileDescriptor, &server->clientsFDs)) {
                    msgBuffer = new char[sizeof (char) * 4 + 1];

                    recv(cliente.fileDescriptor, msgBuffer, sizeof (char) * 4, 0);

                    int msgSize = atoi(msgBuffer);

                    msgBuffer = new char[msgSize + 3];

                    recv(cliente.fileDescriptor, msgBuffer, msgSize, NULL);

                    memcpy(msgBuffer, cliente.ID, 11);
                    msgBuffer[msgSize + 10] = '\n';

                    server->notify(msgBuffer);


                }
            }
            pthread_mutex_unlock(&server->clientsMutex);

        }
    }
}
