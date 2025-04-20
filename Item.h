//
// Created by stell on 10/03/2025.
//

#ifndef LISTA_SPESA_ITEM_H
#define LISTA_SPESA_ITEM_H

#include <string>

//Classe Item che rappresenta un oggetto nella lista
class Item{
public:
    Item(std::string name, std::string category, int quantity);

    std::string getName() const;
    std::string getCategory() const;
    int getQuantity() const;
    void setQuantity(int new_quantity);

private:
    std::string name;
    std::string category;
    int quantity;

};

#endif //LISTA_SPESA_ITEM_H