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