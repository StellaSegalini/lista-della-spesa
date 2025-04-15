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
list.addObserver(user1);

list.addItem(Item("Succo di Frutta", "Bevande", 2));

// Verifica che l'osservatore abbia ricevuto la notifica
ASSERT_EQ(user1->getNotifications().size(), 1);
ASSERT_EQ(user1->getNotifications()[0], "Update for: Lista della Spesa");
}
