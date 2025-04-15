//
// Created by stell on 29/03/2025.
//
#include <gtest/gtest.h>
#include "../User.h"
#include "../ShoppingList.h"

// test dell'osservatore User per la notifica di aggiornamento
TEST(User, ReceivesUpdate) {
ShoppingList list("Lista della Spesa");
auto user1 = std::make_shared<User>("Andrea");

list.addObserver(user1);
list.addItem(Item("Succo di Frutta", "Bevande", 2));

// Verifica che l'utente abbia ricevuto la notifica
testing::internal::CaptureStdout();
list.addItem(Item("Succo di Frutta", "Bevande",2));
std::string output = testing::internal::GetCapturedStdout();
ASSERT_NE(output.find("Utente Andrea ha ricevuto un aggiornamento"), std::string::npos);
ASSERT_NE(output.find("Succo di Frutta"), std::string::npos);
}