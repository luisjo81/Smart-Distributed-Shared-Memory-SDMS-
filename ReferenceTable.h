/* 
 * File:   ReferenceTable.h
 * Author: 
 *
 * Created on September 25, 2015, 7:43 PM
 */

#include <vector>

#ifndef REFERENCETABLE_H
#define	REFERENCETABLE_H

struct reference{
    void * pointer;
    long size;
    char * ownerID;
    int pos;
};

class ReferenceTable {
public:
    ReferenceTable();
    virtual ~ReferenceTable();
    
    void deleteRef(reference&);
    
    reference& searchByPointer(void *);
    reference& searchByOwner(char *);
    
private:
    std::vector<reference> references;
    
    
    
};

#endif	/* REFERENCETABLE_H */

