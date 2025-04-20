//
// Created by stell on 29/03/2025.
//
#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h"

// test dell'osservatore User per la notifica di aggiornamento
TEST(User, ReceivesUpdate) {
ShoppingList list("Lista della Spesa");
User user1 ("Andrea");

list.addObserver(&user1);
list.addItem(Item("Latte", "Bevande", 1));

// Verifica che l'utente abbia ricevuto la notifica
testing::internal::CaptureStdout();
list.addItem(Item("Succo di Frutta", "Bevande",2));
std::string output = testing::internal::GetCapturedStdout();
ASSERT_NE(output.find("Utente Andrea ha ricevuto un aggiornamento"), std::string::npos);
ASSERT_NE(output.find("Succo di Frutta"), std::string::npos);
}

TEST(UserTest, SubscribeAddsUserAsObserver) {
    ShoppingList list1("Lista della Spesa");
    User user1("Marco");

    user1.subscribe(list1);
    //Aggiungo un item per verificare se l'utente riceva la notifica
    testing::internal::CaptureStdout();
    list1.addItem(Item("Pasta", "Alimenti", 1));
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(output.find("Utente Marco ha ricevuto un aggiornamento"), std::string::npos);
    ASSERT_NE(output.find("Pasta"), std::string::npos);
}

TEST(UserTest, UnsbscribeStopsnotifications) {
    ShoppingList list1("Lista della Spesa");
    User user2("Luca");

    user2.subscribe(list1);
    user2.unsubscribe(list1);

    //Aggiungo un item, non dovrebbe arrivare alcuna notifica
    testing::internal::CaptureStdout();
    list1.addItem(Item("Latte", "bevande", 1));
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.empty());
}
