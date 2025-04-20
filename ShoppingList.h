//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_SHOPPINGLIST_H
#define LISTA_SPESA_SHOPPINGLIST_H


#include <vector>
#include <algorithm>
#include <string>
#include "Subject.h"
#include "Item.h"
#include <optional>

//Classe ShoppingList
class ShoppingList : public Subject {
private:
    std::string listName;
    std::vector<Item> items;
    std::vector<Observer*> observers;

public:
    explicit ShoppingList(const std::string &listName);

    std::string getListName() const;
    void addItem(const Item &item);
    bool updateItem(const std::string &itemName,
                    std::optional<int> newQuantity = std::nullopt,
                    std::optional<bool> status = std::nullopt);
    void removeItem(const std::string &itemName);
    const std::vector<Item> &getItems() const;
    std::vector<Item> &getItems();

    void addObserver(Observer* observer) override;
    void removeObserver(Observer* observer) override;
    void notifyObservers() override;
};

#endif //LISTA_SPESA_SHOPPINGLIST_H