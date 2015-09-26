/* 
 * File:   Observable.cpp
 * Author: david
 * 
 * Created on September 23, 2015, 7:22 PM
 */

#include "Observable.h"

Observable::Observable() : observers() {
}

Observable::~Observable() {
    
}

void Observable::addObserver(Observer* newObserver){
    observers.push_back(newObserver);
}

void Observable::notify(void * state){
    for(std::list<Observer *>::iterator iterator = observers.begin();
            iterator != observers.end(); ++iterator){
        (* iterator)->update(this, state);
    }
}