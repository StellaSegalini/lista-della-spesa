//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_ITEM_H
#define LISTA_SPESA_ITEM_H

#include <string>

//Classe Item che rappresenta un oggetto nella lista
class Item{
public:
    Item(const std::string& name, const std::string& category, int quantity, bool isBought = false);

    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;
    bool getIsBought() const;
    void setQuantity(int new_quantity);
    void setIsBought(bool status);

private:
    std::string name;
    std::string category;
    int quantity;
    bool isBought;

};

#endif //LISTA_SPESA_ITEM_H