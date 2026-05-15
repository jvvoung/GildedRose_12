// ApprovalTest.cpp

#define APPROVALS_GOOGLETEST
#include <ApprovalTests.hpp>

#include <gtest/gtest.h>

#include <sstream>
#include <string>
#include <vector>

#include "GildedRose.h"
#include "Item.h"

class ApprovalTest : public ::testing::Test {
protected:
  std::string printTextFixture(int days) {
    std::stringstream result;

    result << "OMGHAI!" << "\n";

    std::vector<Item> items = {
        // 일반 아이템
        Item("noname", 0, 0), // TDD1
        Item("noname", 0, 5), // TDD2
        Item("+5 Dexterity Vest", 10, 20), Item("Normal", 5, 0),

        // Sulfuras
        Item("Sulfuras, Hand of Ragnaros", 0, 5),  // TDD3
        Item("Sulfuras, Hand of Ragnaros", -1, 5), // TDD4

        // Aged Brie
        Item("Aged Brie", 0, 0),  // TDD5
        Item("Aged Brie", 0, 50), // TDD6
        Item("Aged Brie", 5, 10),

        // Backstage Pass
        Item("Backstage passes to a TAFKAL80ETC concert", 15, 0), // TDD7
        Item("Backstage passes to a TAFKAL80ETC concert", 0, 0),  // TDD8
        Item("Backstage passes to a TAFKAL80ETC concert", 0, 51), // TDD9
        Item("Backstage passes to a TAFKAL80ETC concert", 11, 0),
        Item("Backstage passes to a TAFKAL80ETC concert", 10, 0),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 0)

        // Conjured는 아직 구현 전이면 주석 유지
        // , Item("Conjured Mana Cake", 3, 6)
    };

    GildedRose app(items);

    for (int i = 0; i < days; ++i) {
      result << "-------- day " << i << " --------" << "\n";
      result << "name, sellIn, quality" << "\n";

      for (const auto &item : app.items) {
        result << item.toString() << "\n";
      }

      result << "\n";

      app.updateQuality();
    }

    return result.str();
  }
};

TEST_F(ApprovalTest, PrintTextFixture) {
  ApprovalTests::Approvals::verify(printTextFixture(2));
}