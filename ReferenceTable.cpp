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

void ReferenceTable::deleteRef(reference& toDelete){
    references.erase(references.begin() + toDelete.pos);
}

reference& ReferenceTable::searchByOwner(char* ID){
    for(std::vector<reference>::iterator iterator = references.begin();
            iterator != references.end() ;++iterator){
        if((* iterator).ownerID == ID){
            return *iterator;
        }
    }
}

reference& ReferenceTable::searchByPointer(void* pointer){
    for(std::vector<reference>::iterator iterator = references.begin();
            iterator != references.end() ;++iterator){
        if((* iterator).pointer == pointer){
            return *iterator;
        }
    }
}