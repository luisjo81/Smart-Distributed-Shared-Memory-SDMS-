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
    
    explicit d_pointer(void * pointer){
        machine = * (int *)pointer;
        this->pointer = *(int *)(pointer + sizeof (int));
    }
    
    explicit d_pointer(d_pointer& orig){
        this->machine = orig.machine;
        this->pointer = orig.pointer;
    }

    virtual d_pointer& operator=(void * pointer) {
        machine = * (int *)pointer;
        this->pointer = *(int *)(pointer + sizeof (int));
    }

    bool operator==(d_pointer& otherPointer) {
        return (this->machine == otherPointer.machine
                && this->pointer == otherPointer.pointer);
    }
    
};

struct d_pointer_size : public d_pointer {
    
    explicit d_pointer_size(d_pointer_size& orig) : d_pointer::d_pointer(orig){
        this->size = orig.size;
    }
    long size;
    
    explicit d_pointer_size(void * pointer) : d_pointer::d_pointer(pointer){
        size = *(long *)(pointer + sizeof(int) * 2);
    }
    
    virtual d_pointer_size& operator = (void * pointer){
        d_pointer::operator = (pointer);
        size = *(long *)(pointer + sizeof(int) * 2);
    }
};



struct d_pointer_size_type : public d_pointer_size {
    
    d_pointer_size_type(d_pointer_size_type& orig): d_pointer_size::d_pointer_size(orig){
        this->references = orig.references;
        this->type = orig.type;
    }
    
    char references;
    char type;
    
    d_pointer_size_type(void * pointer) : d_pointer_size::d_pointer_size(pointer){
        references = *(char *)(pointer + sizeof(int) * 2 + sizeof(long));
        type = *(char *)(pointer + sizeof(int) * 2 + sizeof(long) + sizeof(char));
        
    }
    
    virtual d_pointer_size_type& operator = (void * pointer){
        references = *(char *)(pointer + sizeof(int) * 2 + sizeof(long));
        type = *(char *)(pointer + sizeof(int) * 2 + sizeof(long) + sizeof(char));
    }
};
#endif	/* D_POINTERS_H */

