//
// Created by stell on 20/04/2025.
//
#include "User.h"
#include "ShoppingList.h"
#include <iostream>

User::User(const std::string &name) : name(name) {}

void User::update(const ShoppingList &shoppingList) {
    std::cout << " Utente " << name << " ha ricevuto un aggiornamento sulla lista: " << shoppingList.getListName() << "\n";
    for (const auto &item : shoppingList.getItems()) {
        std::string stato = item.getIsBought() ? "[Comprato]" : "[Da comprare]";
        std::cout << "- " << item.getName() << " (" << item.getCategory()
        << ") -Quantita': " << item.getQuantity() << " " << stato << "\n";
    }
    std::cout << std::endl;
}