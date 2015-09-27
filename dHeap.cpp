/* 
 * File:   dHeap.cpp
 * Author: 
 * 
 * Created on September 26, 2015, 12:45 PM
 */
#include <stddef.h>
#include "dHeap.h"

dHeap* dHeap::m_pInstance = NULL;


dHeap* dHeap::Instance()
{
    if (!m_pInstance)
        m_pInstance = new dHeap;
    
    return m_pInstance;

}


dHeap::dHeap(char * path) {
}

dHeap::~dHeap() {
}

d_pointer& operator ++(d_pointer& pointer){
    
    dHeapReferenceTable heapReferenceTable = dHeap::Instance()->reference;
    
    pointer(heapReferenceTable.findAfterReference(
            heapReferenceTable.searchByPointer(pointer)));
    
    return pointer;
}

d_pointer& operator --(d_pointer& pointer){
    
    dHeapReferenceTable heapReferenceTable = dHeap::Instance()->reference;
    
    pointer(heapReferenceTable.findBeforeReference(
            heapReferenceTable.searchByPointer(pointer)));
    
    return pointer;
}


d_pointer& operator ++(d_pointer& pointer, int){
    
    dHeapReferenceTable heapReferenceTable = dHeap::Instance()->reference;
    
    d_pointer temp = (d_pointer) heapReferenceTable.searchByPointer(pointer).pointer;
    
    pointer = heapReferenceTable.findAfterReference(
            heapReferenceTable.searchByPointer(pointer));
    
    return temp;
}
    
d_pointer& operator --(d_pointer& pointer, int){
    
    dHeapReferenceTable heapReferenceTable = dHeap::Instance()->reference;
    
    d_pointer temp = (d_pointer) heapReferenceTable.searchByPointer(pointer).pointer;
    
    pointer = heapReferenceTable.findBeforeReference(heapReferenceTable.searchByPointer(pointer)).pointer;
    
    return temp;
}