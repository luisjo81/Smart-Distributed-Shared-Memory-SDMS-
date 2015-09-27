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
    
    int commandIndex;
    
    if((commandIndex = request.find("d_calloc:")) != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_calloc(clientID, request.substr(commandIndex, request.length() - 11)));
    }else if((commandIndex =request.find("d_get:")) != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_get(clientID, request.substr(commandIndex, request.length() - 11)));
    }else if((commandIndex = request.find("d_set:")) != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_set(clientID, request.substr(commandIndex, request.length() - 11)));
    }else if((commandIndex = request.find("d_free:")) != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_free(clientID, request.substr(commandIndex, request.length() - 11)));
    }else if((commandIndex = request.find("d_status:")) != request.npos){
        ((Server *) obs)->sendMessage(clientID ,
                d_status());
    }
    
    free(clientID);
}

void * SDSMMemoryNode::run(void * param){
    SDSMMemoryNode * node = (SDSMMemoryNode *) param;
    while(node->statusServer.isRunning() || node->clientsServer.isRunning()){
        
    }   
}

std::string SDSMMemoryNode::d_calloc(char *, std::string pSize){
    
}

std::string SDSMMemoryNode::d_free(char * clientID, std::string toFree){
    d_pointer_size pointer((void *) toFree.data());
    reference ref = refTable.searchByPointer((void *) pointer.pointer);
    
    if(ref.ownerID == clientID){
        refTable.deleteRef(ref);
        return std::string("0\0");        
    }else{
        return std::string("2\0");
    }
}

std::string SDSMMemoryNode::d_get(char * clientID, std::string toRetrieve){
    d_pointer_size pointer((void *) toRetrieve.data());
    reference ref = refTable.searchByPointer((void *) pointer.pointer);
    
    if(ref.ownerID == clientID && ref.size == pointer.size){
        char * byteStream = (char *)(pointer.pointer + (int) heap);
        return std::string("0").append(byteStream, pointer.size).append("\0");       
    }else{
        return std::string("2\0");
    }
}

std::string SDSMMemoryNode::d_set(char * clientID, std::string toChange){
    d_pointer_size pointer((void *) toChange.substr(0,sizeof(d_pointer_size)).data());
    reference ref = refTable.searchByPointer((void *) pointer.pointer);
    
    if(ref.ownerID == clientID && ref.size == pointer.size){
        void * position =(void *) ((int) heap + pointer.pointer);
        
        memcpy(position, toChange.substr(sizeof(d_pointer_size)).data(), ref.size);
        
        return std::string("0\0");       
    }else{
        return std::string("2\0");
    }
    
}

std::string SDSMMemoryNode::d_status(){

}