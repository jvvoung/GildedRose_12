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

// TDD3
TEST(GildedRoseTest, TDD3_sulfuras) {
  std::vector<Item> items = {Item("Sulfuras, Hand of Ragnaros", 0, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
  EXPECT_EQ(0, app.items[0].sellIn);
  EXPECT_EQ(5, app.items[0].quality);
}

// TDD4
TEST(GildedRoseTest, TDD4_sulfuras) {
  std::vector<Item> items = {Item("Sulfuras, Hand of Ragnaros", -1, 5)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(5, app.items[0].quality);
}

// TDD5
TEST(GildedRoseTest, TDD5_aged_brie) {
  std::vector<Item> items = {Item("Aged Brie", 0, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Aged Brie", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(2, app.items[0].quality);
}

// TDD6
TEST(GildedRoseTest, TDD6_aged_brie) {
  std::vector<Item> items = {Item("Aged Brie", 0, 50)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Aged Brie", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(50, app.items[0].quality);
}