/* 
 * File:   Observer.h
 * Author: david
 *
 * Created on September 23, 2015, 7:22 PM
 */

#ifndef OBSERVER_H
#define	OBSERVER_H

class Observable;

class Observer {
public:
    Observer();
    virtual ~Observer();
    
    virtual void update(Observable *, void *) = 0;
    
private:

};

#endif	/* OBSERVER_H */

