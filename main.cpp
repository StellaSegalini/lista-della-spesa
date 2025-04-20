#include "User.h"
#include "ShoppingList.h"
#include <memory>
#include <iostream>
#include "Item.h"


//esempio di utilizzo
int main(){
    ShoppingList list1 ("Lista Famiglia");
    ShoppingList list2 ("Lista 2");

    User user1("Andrea");
    User user2 ("Marco");

    user1.subscribe(list1);
    user2.subscribe(list2);

    list1.addItem(Item("Succo di Frutta","Bevande", 2, false));
    list2.addItem(Item("Biscotti","Alimenti", 1, false));
    list2.addItem(Item("Latte","Bevande", 1, false));

    std::cout<<"\nAggiornamento della Lista Famiglia:\n";
    list1.updateItem("Succo di Frutta", std::nullopt, true);

    std::cout<<"\nAggiornamento dopo l'aggiunta di oggetti:\n";
    list2.updateItem("Biscotti", 3);

    std::cout<<"\nRimuoviamo 'Succo di Frutta' dalla Lista Famiglia:\n";
    list1.removeItem("Succo di Frutta");

    std::cout<<"\nAggiornamento della Lista 2 :\n";
    list2.updateItem("Biscotti", std::nullopt, true);

    std::cout << "Oggetti comprati nella lista: " << list1.getListName() << " : " << list1.getBoughtItemCount() << std::endl;
    std::cout << "Oggetti ancora da comprare nella lista: " << list2.getListName() << " : " << list2.getUnBoughtItemCount() << std::endl;

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