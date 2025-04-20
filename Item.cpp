//
// Created by stell on 20/04/2025.
//
#include "Item.h"
#include <stdexcept>

Item::Item(const std::string& name,  const std::string& category, int quantity, bool isBought)
    : name(name), category(category), isBought(isBought) {
    if (quantity < 0) {
        throw std::invalid_argument("La quantita' non puo' essere negativa.");
    }
    this->quantity = quantity;
}

    std::string Item::getName() const {
    return name;
}
    std::string Item::getCategory() const {
    return category;
}
    int Item::getQuantity() const {
    return quantity;
}
    void Item::setQuantity(int new_quantity) {
        if (new_quantity < 0) {
            throw std::invalid_argument("La quantita' non puo' essere negativa.");
        }
        quantity = new_quantity;
    }

    bool Item::getIsBought() const {
        return isBought;
    }

    void Item::setIsBought(bool status) {
        isBought = status;
    }
