//
// Created by stell on 29/03/2025.
//
#include <gtest/gtest.h>
#include "../Item.h"

// test per la classe Item
TEST(ItemTest, GetName) {
    Item item("Succo di Frutta", "Bevande", 2);
    ASSERT_EQ(item.getName(), "Succo di Frutta");
}

TEST(ItemTest, GetCategory) {
    Item item("Succo di Frutta", "Bevande", 2);
    ASSERT_EQ(item.getCategory(), "Bevande");
}

TEST(ItemTest, GetQuantity) {
    Item item("Succo di Frutta", "Bevande", 2);
    ASSERT_EQ(item.getQuantity(), 2);
}

TEST(ItemTest, SetQuantity) {
    Item item("Succo di Frutta", "Bevande", 2);
    item.setQuantity(3);
    ASSERT_EQ(item.getQuantity(), 3);
}

//Test per costruzione con quantità negativa
TEST(ItemTest, ConstructorThrowsOnNegativeQuantity){
    ASSERT_THROW(Item("Latte", "Bevande",-1), std::invalid_argument);
}

//Test per setQuantity con quantità negativa
TEST(ItemTest, SetQuantityThrowsOnNegativeQuantity){
    Item item("Latte", "Bevande", 2);
    ASSERT_THROW(item.setQuantity(-5), std::invalid_argument);
}

TEST(ItemTest, SetIsBoughtTrue) {
    Item item("Succo di Frutta", "Bevande", 2);
    item.setIsBought(true);
    EXPECT_TRUE(item.getIsBought());
}

TEST(ItemTest, GetIsBoughtFalse) {
    Item item("Succo di Frutta", "Bevande", 2);
    EXPECT_FALSE(item.getIsBought());
}