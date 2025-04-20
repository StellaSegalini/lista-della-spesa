//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_USER_H
#define LISTA_SPESA_USER_H

#include <string>
#include "Observer.h"

class ShoppingList;

//Classe User (Observer)
class User: public Observer{
private:
    std::string name;
public:
    explicit User(const std::string& name);
    void update(const ShoppingList &shoppingList) override;
};

#endif //LISTA_SPESA_USER_H