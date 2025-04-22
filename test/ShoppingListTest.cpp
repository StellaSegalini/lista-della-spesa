//
// Created by stell on 29/03/2025.
//
#include <gtest/gtest.h>
#include <memory>
#include "../ShoppingList.h"
#include "../User.h"
#include "../Item.h"

// Mock della classe User per verificare le notifiche
class MockUser : public User {
public:
    MockUser(const std::string& name) : User(name) {}

    void update(const ShoppingList& shoppingList) override {
        notifications.push_back("Update for: " + shoppingList.getListName());
    }

    const std::vector<std::string>& getNotifications() const {
        return notifications;
    }

private:
    std::vector<std::string> notifications;
};

TEST(ShoppingListTest, AddItemNotifiesObservers) {
ShoppingList list("Lista della Spesa");
auto user1 = std::make_shared<MockUser>("Andrea");
list.addObserver(user1.get());
list.addItem(Item("Succo di Frutta", "Bevande", 2));

// Verifica che l'osservatore abbia ricevuto la notifica
ASSERT_EQ(user1->getNotifications().size(), 1);
ASSERT_EQ(user1->getNotifications()[0], "Update for: Lista della Spesa");
}

TEST(ShoppingListTest, RemoveItemNotifiesObservers) {
    ShoppingList list("Lista della Spesa");
    auto user1 = std::make_shared<MockUser>("Andrea");
    list.addObserver(user1.get());
    Item item("Succo di Frutta", "Bevande", 2);
    list.addItem(item);
    list.removeItem("Succo di Frutta");

// Verifica che l'osservatore abbia ricevuto la notifica
    ASSERT_EQ(user1->getNotifications().size(), 2);
    ASSERT_EQ(user1->getNotifications()[1], "Update for: Lista della Spesa");
}

TEST(ShoppingListTest, UpdateItemNotifiesObservers) {
    ShoppingList list("Lista della Spesa");
    auto user1 = std::make_shared<MockUser>("Andrea");
    list.addObserver(user1.get());
    Item item("Succo di Frutta", "Bevande", 2);
    list.addItem(item);
    list.updateItem("Succo di Frutta",3, true);

// Verifica che l'osservatore abbia ricevuto la notifica
    ASSERT_EQ(user1->getNotifications().size(), 2);
    ASSERT_EQ(user1->getNotifications()[1], "Update for: Lista della Spesa");
}

TEST(ShoppingListTest, GetBoughtItemCount) {
    ShoppingList list("Lista della Spesa");
    list.addItem(Item("Succo di Frutta","Bevande", 2, true));
    list.addItem(Item("Biscotti", "Alimenti", 1, false));
    list.addItem(Item("Latte","Bevande", 1, true));


// Verifica che la funzione ritorni il numero corretto di articoli comprati
    ASSERT_EQ(list.getBoughtItemCount(), 2);
}

TEST(ShoppingListTest, GetUnBoughtItemCount) {
    ShoppingList list("Lista della Spesa");
    list.addItem(Item("Succo di Frutta","Bevande", 2, true));
    list.addItem(Item("Biscotti", "Alimenti", 1, false));
    list.addItem(Item("Latte","Bevande", 1, true));


// Verifica che la funzione ritorni il numero corretto di articoli non comprati
    ASSERT_EQ(list.getUnBoughtItemCount(), 1);
}



