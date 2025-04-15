//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_SUBJECT_H
#define LISTA_SPESA_SUBJECT_H


#include <memory>
#include "Observer.h"

//Interfaccia Subject (Observable)
class Subject {
public:
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer)=0;
    virtual void notifyObservers()=0;
    virtual ~Subject()=default;
};

#endif //LISTA_SPESA_SUBJECT_H