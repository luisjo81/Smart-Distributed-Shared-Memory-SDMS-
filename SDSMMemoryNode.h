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
    
    char * d_calloc(std::string&);
    char * d_get(std::string&);
    char * d_set(std::string&);
    char * d_free(std::string&);
    char * d_status();
    
private:
    void * heap;
    int size, port, statusPort;
    
    ReferenceTable refTable;
    
    Server clientsServer;
    Server statusServer;
};

#endif	/* SDSMMEMORYNODE_H */

