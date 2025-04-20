//
// Created by stell on 20/04/2025.
//
#include "ShoppingList.h"
#include <algorithm>

ShoppingList::ShoppingList(const std::string& listName) : listName(listName) {}

std::string ShoppingList::getListName() const {
    return listName;
}

void ShoppingList::addItem(const Item& newItem) {
    for(const auto& item : items) {
        if(item.getName() == newItem.getName()) {
            //Item già presente, non aggiungere
            return;
        }
    }
    items.push_back(newItem);
    notifyObservers();
}

void ShoppingList::updateItemQuantity(const std::string& itemName, int newQuantity) {
    for(auto& item : items){
        if (item.getName() == itemName) {
            item.setQuantity(newQuantity);
            notifyObservers();
            break;
        }
    }
}

void ShoppingList::removeItem(const std::string& itemName){
    auto it = std::remove_if(items.begin(), items.end(),
                             [&](const Item& item) { return item.getName() == itemName;});
    if(it != items.end()) {
        items.erase(it, items.end());
        notifyObservers();
    }
}

//versione non-const per modifica
std::vector<Item>& ShoppingList::getItems() {
    return items;
}

//versione const per lettura
const std::vector<Item>& ShoppingList::getItems() const {
    return items;
}

void ShoppingList::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void ShoppingList::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void ShoppingList::notifyObservers() {
    for (const auto& observer : observers){
        observer->update(*this);
    }
}