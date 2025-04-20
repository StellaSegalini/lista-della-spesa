//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_USER_H
#define LISTA_SPESA_USER_H

#include <string>
#include <vector>
#include "Observer.h"

class ShoppingList;

//Classe User (Observer)
class User: public Observer{
private:
    std::string name;
    std::vector<ShoppingList*> observedList; //Elenco delle liste osservate
public:
    explicit User(const std::string& name);

    void update(const ShoppingList &shoppingList) override;

    void subscribe(ShoppingList& shoppingList);

    void unsubscribe(ShoppingList& shoppingList);

    ~User(); //Distrutture per disiscriversi da tutte le liste
};

#endif //LISTA_SPESA_USER_H