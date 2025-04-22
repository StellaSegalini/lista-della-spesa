//
// Created by stell on 29/03/2025.
//
#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h"

// test dell'osservatore User per la notifica di aggiornamento
TEST(UserTest, ReceivesUpdate) {
    ShoppingList list("Lista della Spesa");
    User user1 ("Andrea");

    user1.subscribe(list);

    // add item
    testing::internal::CaptureStdout();
    list.addItem(Item("Latte", "Bevande", 1));
    std::string outputAdd = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputAdd.find("Utente Andrea ha ricevuto un aggiornamento"), std::string::npos);
    ASSERT_NE(outputAdd.find("Latte"), std::string::npos);

    //update item
    testing::internal::CaptureStdout();
    list.updateItem("Latte", 2, true);
    std::string outputUpdate = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputUpdate.find("Utente Andrea ha ricevuto un aggiornamento"), std::string::npos);
    ASSERT_NE(outputUpdate.find("Latte"), std::string::npos);

    //remove item
    testing::internal::CaptureStdout();
    list.removeItem("Latte");
    std::string outputRemove = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputRemove.find("Utente Andrea ha ricevuto un aggiornamento"), std::string::npos);
}

TEST(UserTest, SubscribeAddsUserAsObserver) {
    ShoppingList list1("Lista della Spesa");
    User user1("Marco");

    user1.subscribe(list1);
    //Aggiungo un item per verificare se l'utente riceva la notifica
    testing::internal::CaptureStdout();
    list1.addItem(Item("Pasta", "Alimenti", 1));
    std::string outputAdd = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputAdd.find("Utente Marco ha ricevuto un aggiornamento"), std::string::npos);
    ASSERT_NE(outputAdd.find("Pasta"), std::string::npos);

    //update item
    testing::internal::CaptureStdout();
    list1.updateItem("Pasta", 3, true);
    std::string outputUpdate = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputUpdate.find("Utente Marco ha ricevuto un aggiornamento"), std::string::npos);
    ASSERT_NE(outputUpdate.find("Pasta"), std::string::npos);

    //remove item
    testing::internal::CaptureStdout();
    list1.removeItem("Pasta");
    std::string outputRemove = testing::internal::GetCapturedStdout();
    ASSERT_NE(outputRemove.find("Utente Marco ha ricevuto un aggiornamento"), std::string::npos);
}

TEST(UserTest, UnsbscribeStopsnotifications) {
    ShoppingList list1("Lista della Spesa");
    User user2("Luca");

    user2.subscribe(list1);
    user2.unsubscribe(list1);

    //Aggiungo un item, non dovrebbe arrivare alcuna notifica
    testing::internal::CaptureStdout();
    list1.addItem(Item("Latte", "Bevande", 1));
    std::string outputAdd = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(outputAdd.empty());

    //update item
    testing::internal::CaptureStdout();
    list1.updateItem("Latte", 2, true);
    std::string outputUpdate = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(outputUpdate.empty());

    //remove item
    testing::internal::CaptureStdout();
    list1.removeItem("Latte");
    std::string outputRemove = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(outputRemove.empty());
}
