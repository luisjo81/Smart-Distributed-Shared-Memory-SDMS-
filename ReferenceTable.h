/* 
 * File:   ReferenceTable.h
 * Author: 
 *
 * Created on September 25, 2015, 7:43 PM
 */

#include <list>

#ifndef REFERENCETABLE_H
#define	REFERENCETABLE_H

struct reference{
    void * pointer;
    int size;
    char * ownerID;
};

class ReferenceTable {
public:
    ReferenceTable();
    virtual ~ReferenceTable();
    
    reference searchByPointer(void *);
    reference searchByOwner(char *);
    
private:
    std::list<reference> references;
    
    
    
};

#endif	/* REFERENCETABLE_H */

