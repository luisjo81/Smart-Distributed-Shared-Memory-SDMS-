/* 
 * File:   dHeapReference.h
 * Author: 
 *
 * Created on September 26, 2015, 1:45 PM
 */

#include <list>

#include "d_pointers.h"

#ifndef DHEAPREFERENCE_H
#define	DHEAPREFERENCE_H

struct dHeapReference{
    int ID;
    d_pointer_size_type pointer;
};

class dHeapReferenceTable {
public:
    dHeapReferenceTable();
    virtual ~dHeapReferenceTable();
private:
    
    std::list<dHeapReference> references;
        
};

#endif	/* DHEAPREFERENCE_H */

