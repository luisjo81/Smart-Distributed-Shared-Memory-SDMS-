/* 
 * File:   Server.h
 * Author: david
 *
 * Created on September 15, 2015, 7:30 PM
 */

#include <string.h>
#include <vector>
#include <cstdlib>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>

#include "Observable.h"

#ifndef SERVER_H
#define	SERVER_H

struct client{
    int fileDescriptor;
    char * ID;
};

class Server : public Observable {
public:
    Server(int);
    virtual ~Server();
    
    bool isRunning();
    
    void sendMessage(char * ID, std::string message);
private:
    
    static void * clientsHandler(void * param);
    
    static void * ioHandler(void* param);
    
    bool running;
    
    pthread_mutex_t clientsMutex;
    
    fd_set clientsFDs;
    
    int highestFD;
    int serverSocket;
    sockaddr_in serv_addr;
    std::vector<client> clients;
};

#endif	/* SERVER_H */

