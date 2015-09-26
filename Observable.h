/* 
 * File:   Observable.h
 * Author: david
 *
 * Created on September 23, 2015, 7:22 PM
 */

#include "Observer.h"
#include <list>

#ifndef OBSERVABLE_H
#define	OBSERVABLE_H

class Observable {
public:
    Observable();
    virtual ~Observable();
    
    void addObserver(Observer* newObserver);
    
protected:
    void notify(void * state);
    
private:
    
    std::list<Observer*> observers;

};

#endif	/* OBSERVABLE_H */

