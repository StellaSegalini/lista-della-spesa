#include "User.h"
#include "ShoppingList.h"
#include <memory>
#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "Item.h"


//esempio di utilizzo
int main(){
    ShoppingList list1 ("Lista Famiglia");
    auto user1  = std::make_shared<User>("Andrea");
    auto user2 = std::make_shared<User>("Marco");

    list1.addObserver(user1);
    list1.addObserver(user2);

    list1.addItem(Item("Succo di Frutta","Bevande", 2));
    list1.addItem(Item("Biscotti","Alimenti", 1));

    std::cout<<"\nAggiornamento dopo l'aggiunta di oggetti:\n";
    list1.updateItemQuantity("Biscotti", 3);

    std::cout<<"\nRimuoviamo 'Succo di Frutta' dalla Lista Famiglia:\n";
    list1.removeItem("Succo di Frutta");
    return 0;
}