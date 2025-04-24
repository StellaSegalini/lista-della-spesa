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

TEST(ShoppingListTest, RemoveNonExistingItem) {
    ShoppingList list("Lista della Spesa");
    list.addItem(Item("Latte", "Bevande", 1));
    list.removeItem("Pane"); //Oggetto non presente

    //Deve esserci ancora solo 1 elemento
    ASSERT_EQ(list.getItems().size(), 1);
    ASSERT_EQ(list.getItems()[0].getName(), "Latte");
}

TEST(ShoppingListTest, UpdateNonExistingItem) {
    ShoppingList list("Lista della Spesa");
    list.addItem(Item("Latte", "Bevande", 1));

    //Tentativo aggiornamento su item inesistente
    bool result = list.updateItem("Pane", 2, true);
    ASSERT_FALSE(result);
}

TEST(ShoppingListTest, ItemCountCheck) {
    ShoppingList list("Lista della Spesa");
    list.addItem(Item("Latte", "Bevande", 1)); // non comprato
    list.addItem(Item("Pane", "Alimenti", 1, true)); //comprato
    list.addItem(Item("Biscotti", "Dolci", 2, true)); //comprato

    //Controlli iniziali
    ASSERT_EQ(list.getItems().size(), 3);
    ASSERT_EQ(list.getBoughtItemCount(), 2);
    ASSERT_EQ(list.getUnBoughtItemCount(), 1);

    //Rimuovo un item
    list.removeItem("Latte");

    //Controlli dopo rimozione
    ASSERT_EQ(list.getItems().size(), 2);
    ASSERT_EQ(list.getBoughtItemCount(), 2);
    ASSERT_EQ(list.getUnBoughtItemCount(), 0);

    //Aggiorno un item
    list.updateItem("Biscotti", std::nullopt, false);

    //Controllo dopo aggiornamento
    ASSERT_EQ(list.getItems().size(), 2);
    ASSERT_EQ(list.getBoughtItemCount(), 1);
    ASSERT_EQ(list.getUnBoughtItemCount(), 1);
}
