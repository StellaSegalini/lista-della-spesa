//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_USER_H
#define LISTA_SPESA_USER_H

#include <iostream>
#include <string>
#include "Observer.h"
#include "ShoppingList.h"

//Classe User (Observer)
class User: public Observer{
private:
    std::string name;
public:
    User(const std::string& name) : name(name) {}
    void update(const ShoppingList &shoppingList) override {
        std::cout << " Utente "<<name<<" ha ricevuto un aggiornamento sulla lista:"<<shoppingList.getListName()<<"\n";
        for (const auto& item : shoppingList.getItems()) {
            std::cout << "- "<<item.getName()<<" ("<<item.getCategory()<< ")- Quantita': "<<item.getQuantity()<< "\n";
        }
        std::cout<<std::endl;
    }
};

#endif //LISTA_SPESA_USER_H