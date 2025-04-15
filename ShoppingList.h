//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_SHOPPINGLIST_H
#define LISTA_SPESA_SHOPPINGLIST_H


#include <vector>
#include <algorithm>
#include "Subject.h"
#include "Item.h"

//Classe ShoppingList (Observable)
class ShoppingList : public Subject {
private:
    std::string listName;
    std::vector<Item> items;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    ShoppingList(const std::string &listName) : listName(listName) {}

    std::string getListName() const {return listName;}

     void addItem(const Item &item){
        items.push_back(item);
        notifyObservers(); //notifica gli osservatori
    }

    void updateItemQuantity(const std::string &itemName, int newQuantity){
        for(auto &item : items){
            if (item.getName() == itemName) {
                item.setQuantity(newQuantity);
                notifyObservers();
                break;
            }
        }
    }
    void removeItem(const std::string &itemName){
        auto it = std::remove_if(items.begin(), items.end(),
                                 [&](const Item &item) { return item.getName() == itemName;});
        if(it != items.end()) {
            items.erase(it, items.end());
            notifyObservers();
        }
    }
    const std::vector<Item>& getItems() const {
        return items;
    }

    void addObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyObservers() override {
        for (const auto& observer : observers){
            observer->update(*this);
        }
    }
};

#endif //LISTA_SPESA_SHOPPINGLIST_H