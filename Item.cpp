//
// Created by stell on 20/04/2025.
//
#include "Item.h"

Item::Item(const std::string& name,  const std::string& category, int quantity)
    : name(std::move(name)), category(std::move(category)), quantity(quantity) {}

    std::string Item::getName() const { return name; }
    std::string Item::getCategory() const { return category; }
    int Item::getQuantity() const { return quantity; }
    void Item::setQuantity(int new_quantity) {quantity = new_quantity; }
