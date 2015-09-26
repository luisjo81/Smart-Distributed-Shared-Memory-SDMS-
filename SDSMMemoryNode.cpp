/* 
 * File:   SDSMMemoryNode.cpp
 * Author: 
 */

#include "SDSMMemoryNode.h"

SDSMMemoryNode::SDSMMemoryNode(int size, int port, int statusPort) :
clientsServer(port), statusServer(statusPort) {
    heap = malloc(size);
    this->size = size;
    this->port = port;
    this->statusPort = statusPort;
    
    clientsServer.addObserver(this);
    statusServer.addObserver(this);
}

SDSMMemoryNode::~SDSMMemoryNode() {
    free(heap);
    clientsServer.~Server();
    statusServer.~Server();
}

void SDSMMemoryNode::update(Observable* obs, void* msg){
    std::string request = (char *) msg;
    
    char * clientID =  &request.substr(request.length() - 11, 11)[0];
    
    if(request.find("d_calloc") != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_calloc(request));
    }else if(request.find("d_get") != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_get(request));
    }else if(request.find("d_set") != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_set(request));
    }else if(request.find("d_free") != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_free(request));
    }else if(request.find("d_status") != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_status());
    }
}

void * SDSMMemoryNode::run(void * param){
    SDSMMemoryNode * node = (SDSMMemoryNode *) param;
    while(node->statusServer.isRunning() || node->clientsServer.isRunning()){
        
    }   
}

char * SDSMMemoryNode::d_calloc(std::string&){
    
}

char * SDSMMemoryNode::d_free(std::string& toFree){
    d_pointer_size pointer = (void *) toFree.data();
}

char * SDSMMemoryNode::d_get(std::string&){

}

char * SDSMMemoryNode::d_set(std::string&){

}

char * SDSMMemoryNode::d_status(){

}