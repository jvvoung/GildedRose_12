#include "GildedRose.h"
#include <gtest/gtest.h>

// TDD1
TEST(GildedRoseTest, TDD1_noname) {
  std::vector<Item> items = {Item("noname", 0, 0)};
  GildedRose app(items);

  app.updateQuality();

  EXPECT_EQ("noname", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(0, app.items[0].quality);
}

// TDD2
TEST(GildedRoseTest, TDD2_noname) {
  std::vector<Item> items = {Item("noname", 0, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("noname", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(3, app.items[0].quality);
}