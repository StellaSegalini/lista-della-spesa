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

void User::subscribe(ShoppingList &shoppingList) {
    if (std::find(observedList.begin(), observedList.end(), &shoppingList) ==observedList.end()){
        observedList.push_back(&shoppingList);
        shoppingList.addObserver(this); //Aggiungi l'utente come osservatore della lista
    }
}

void User::unsubscribe(ShoppingList &shoppingList) {
    auto it = std::find(observedList.begin(), observedList.end(), &shoppingList);
    if (it !=observedList.end()) {
        observedList.erase(it);
        shoppingList.removeObserver(this); //Rimuovi l'utente come osservatore della lista
    }
}

User::~User() {
    //Quando l'utente viene distrutto, si disiscrive da tutte le liste osservate
    for (auto list : observedList) {
        list->removeObserver(this);
    }
}
