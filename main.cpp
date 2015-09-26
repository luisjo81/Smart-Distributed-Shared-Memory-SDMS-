/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on September 13, 2015, 12:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <pthread.h>

#include "SDSMMemoryNode.h"

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc != 4) {
	std::cerr << "usage: ./SDSMMemoryNode <cantidad de memoria><medida M|G> <puerto> <puerto estado>\n";

	return 1;
    } else {
        
        int size, port = atoi(argv[2]), statePort = atoi(argv[3]);
        
        std::string firstArg = std::string(argv[1]);
        
        if (firstArg.find('M')){
            size = atoi(firstArg.substr(0, firstArg.find('M')).data())*1024;
        }else{
            size = atoi(firstArg.substr(0, firstArg.find('G')).data())*1024*1024;            
        }

        
        SDSMMemoryNode memoryNode = SDSMMemoryNode(size, port, statePort);
        
        pthread_t nodeThread;
        
        pthread_create(&nodeThread, NULL, SDSMMemoryNode::run, &memoryNode);
        
        pthread_join(nodeThread, NULL);
        
        
        return 0;
    }
}

