#include "User.h"
#include "ShoppingList.h"
#include <memory>
#include <iostream>
#include "Item.h"


//esempio di utilizzo
int main(){
    ShoppingList list1 ("Lista Famiglia");
    User user1("Andrea");
    User user2 ("Marco");

    list1.addObserver(&user1);
    list1.addObserver(&user2);

    list1.addItem(Item("Succo di Frutta","Bevande", 2, false));
    list1.addItem(Item("Biscotti","Alimenti", 1, false));

    for (auto& item : list1.getItems()) {
        if (item.getName() == "Succo di Frutta") {
            item.setIsBought(true);
        }
    }

    std::cout<<"\nAggiornamento dopo l'aggiunta di oggetti:\n";
    list1.updateItem("Biscotti", 3);

    std::cout<<"\nRimuoviamo 'Succo di Frutta' dalla Lista Famiglia:\n";
    list1.removeItem("Succo di Frutta");

    std::cout<<"\nAggiornamento dopo l'aggiunta di oggetti:\n";
    list1.updateItem("Biscotti", std::nullopt, true);

    std::cout << "Oggetti comprati: " << list1.getBoughtItemCount() << std::endl;
    std::cout << "Oggetti ancora da comprare: " << list1.getUnBoughtItemCount() << std::endl;

    bool updated = list1.updateItem("Yogurt", 1, true);
    if(!updated) {
        std::cout << "'Yogurt' non e' presente nella lista. Nessun aggiornamento effettuato.\n";
    }

    try {
        list1.addItem(Item("Latte","Bevande", -2));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Errore: " << e.what() <<std::endl;
    }
    return 0;
}