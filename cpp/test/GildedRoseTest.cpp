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

// TDD7
TEST(GildedRoseTest, TDD7_backstage) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 15, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
  EXPECT_EQ(14, app.items[0].sellIn);
  EXPECT_EQ(1, app.items[0].quality);
}

// TDD8
TEST(GildedRoseTest, TDD8_backstage) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 0, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(0, app.items[0].quality);
}

// TDD9
TEST(GildedRoseTest, TDD9_backstage) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 0, 51)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[0].name);
  EXPECT_EQ(-1, app.items[0].sellIn);
  EXPECT_EQ(0, app.items[0].quality);
}

// TDD10
TEST(GildedRoseTest, TDD10_empty_items) {
  std::vector<Item> items = {};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(0, app.items.size());
}

// ---------------------------------------------------------------------------
// Step 1 보강 — 교재 예시·경계값 회귀 테스트 (리팩토링 전 동작 고정)
// ---------------------------------------------------------------------------

TEST(GildedRoseTest, NormalItemDegradesByOneEachDay) {
  std::vector<Item> items = {Item("+5 Dexterity Vest", 10, 20)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(9, app.items[0].sellIn);
  EXPECT_EQ(19, app.items[0].quality);
}

TEST(GildedRoseTest, QualityNeverNegative) {
  std::vector<Item> items = {Item("Normal", 5, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(4, app.items[0].sellIn);
  EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, AgedBrieIncreasesQualityBeforeSellIn) {
  std::vector<Item> items = {Item("Aged Brie", 5, 10)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(4, app.items[0].sellIn);
  EXPECT_EQ(11, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePass_SellIn11_IncreasesByOne) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 11, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(10, app.items[0].sellIn);
  EXPECT_EQ(1, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePass_SellIn10_IncreasesByTwo) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 10, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(9, app.items[0].sellIn);
  EXPECT_EQ(2, app.items[0].quality);
}

TEST(GildedRoseTest, BackstagePass_SellIn5_IncreasesByThree) {
  std::vector<Item> items = {
      Item("Backstage passes to a TAFKAL80ETC concert", 5, 0)};
  GildedRose app(items);
  app.updateQuality();
  EXPECT_EQ(4, app.items[0].sellIn);
  EXPECT_EQ(3, app.items[0].quality);
}