//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_OBSERVER_H
#define LISTA_SPESA_OBSERVER_H


class ShoppingList;

//Interfaccia Observer
class Observer {
public:
    virtual void update(const ShoppingList &shoppingList) = 0;
    virtual ~Observer() = default;
};

#endif //LISTA_SPESA_OBSERVER_H