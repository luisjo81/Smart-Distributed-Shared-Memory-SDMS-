/* 
 * File:   dHeap.h
 * Author:
 *
 * Created on September 26, 2015, 12:44 PM
 */

#include "d_pointers.h"
#include "dHeapReferenceTable.h"

#include <string>

#ifndef DHEAP_H
#define	DHEAP_H

class dHeap{
    
    friend d_pointer& operator++(d_pointer&);
    friend d_pointer& operator++(d_pointer&, int);
    
public:
    
    static dHeap* Instance();
    bool openLogFile(std::string logFile);
    void writeToLogFile();
    bool closeLogFile(); 
    
    
    dHeap(char * path);
    virtual ~dHeap();
    
    d_pointer_size_type dMalloc(int size, std::string type);
    
    void dFree(d_pointer_size_type toFree);
    
private:
    
    dHeap(){};
    dHeap(dHeap const&){};
    dHeap& operator=(dHeap const&){};
    static dHeap* m_pInstance;
    
    dHeapReferenceTable reference;

};

#endif	/* DHEAP_H */

