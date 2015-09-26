/* 
 * File:   SDSMMemoryNode.h
 * Author: 
 *
 * Created on September 13, 2015, 1:15 PM
 */

#include <cstdlib>
#include <string>

#include <pthread.h>

#include "Server.h"
#include "Observer.h"
#include "ReferenceTable.h"

#include "d_pointers.h"

#ifndef SDSMMEMORYNODE_H
#define	SDSMMEMORYNODE_H

class SDSMMemoryNode : public Observer {
public:
    SDSMMemoryNode(int size, int port, int statusPort);
    virtual ~SDSMMemoryNode();
    
    static void * run(void * node);
    
    void update(Observable *, void *);
    
    std::string d_calloc(char *, std::string);
    std::string d_get(char * , std::string);
    std::string d_set(char * ,std::string);
    std::string d_free(char *, std::string);
    std::string d_status();
    
private:
    void * heap;
    int size, port, statusPort;
    
    ReferenceTable refTable;
    
    Server clientsServer;
    Server statusServer;
};

#endif	/* SDSMMEMORYNODE_H */

