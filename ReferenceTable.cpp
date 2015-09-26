/* 
 * File:   ReferenceTable.cpp
 * Author: david
 * 
 * Created on September 25, 2015, 7:43 PM
 */

#include "ReferenceTable.h"

ReferenceTable::ReferenceTable() {
}

ReferenceTable::~ReferenceTable() {
}

reference ReferenceTable::searchByOwner(char* ID){
    for(std::list<reference>::iterator iterator = references.begin();
            iterator != references.end() ;++iterator){
        if((* iterator).ownerID == ID){
            return *iterator;
        }
    }
}

reference ReferenceTable::searchByPointer(void* pointer){
    for(std::list<reference>::iterator iterator = references.begin();
            iterator != references.end() ;++iterator){
        if((* iterator).pointer == pointer){
            return *iterator;
        }
    }
}