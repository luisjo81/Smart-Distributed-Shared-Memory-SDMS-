/* 
 * File:   d_pointers.h
 * Author: 
 *
 * Created on September 25, 2015, 8:12 PM
 */

#ifndef D_POINTERS_H
#define	D_POINTERS_H

struct d_pointer {
    int machine;
    int pointer;
    
    d_pointer(void * pointer){
        machine = * (int *)pointer;
        this->pointer = *(int *)(pointer + sizeof (int));
    }

    virtual d_pointer& operator=(void * pointer) {
        machine = * (int *)pointer;
        this->pointer = *(int *)(pointer + sizeof (int));
    }

    bool operator==(d_pointer& otherPointer) {
        return (this->machine == otherPointer.machine
                && this->pointer == otherPointer.pointer);
    }

    operator void *() {
        return &machine;
    }
};

struct d_pointer_size : public d_pointer {
    long size;
    
    d_pointer_size(void * pointer) : d_pointer::d_pointer(pointer){
        size = *(long *)(pointer + sizeof(int) * 2);
    }
    
    virtual d_pointer_size& operator = (void * pointer){
        d_pointer::operator = (pointer);
        size = *(long *)(pointer + sizeof(int) * 2);
    }
};

struct d_pointer_size_type : public d_pointer_size {
    char references;
    char type;
};
#endif	/* D_POINTERS_H */

