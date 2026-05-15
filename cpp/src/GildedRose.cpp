#include "GildedRose.h"

#include "AgedBrieItem.h"
#include "BackstagePassItem.h"
#include "FoodBeverageItem.h"
#include "GildedRoseItem.h"
#include "NormalItem.h"
#include "SulfurasItem.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

std::unique_ptr<GildedRoseItem> GildedRose::createItem(Item& item) {
    std::unique_ptr<GildedRoseItem> gildedRoseItem;
    if (item.name == AGED_BRIE) {
        gildedRoseItem = std::make_unique<AgedBrieItem>(item);
    } else if (item.name == BACKSTAGE_PASS) {
        gildedRoseItem = std::make_unique<BackstagePassItem>(item);
    } else if (item.name == SULFURAS) {
        gildedRoseItem = std::make_unique<SulfurasItem>(item);
    } else if (item.name.find("[F&B]") != std::string::npos) {
        gildedRoseItem = std::make_unique<FoodBeverageItem>(item);
    } else {
        gildedRoseItem = std::make_unique<NormalItem>(item);
    }
    return gildedRoseItem;
}

void GildedRose::updateSellIn(Item& item) {
    if (item.name != SULFURAS) {
        item.sellIn = item.sellIn - 1;
    }
}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        updateItem(item);
    }
}

void GildedRose::updateItem(Item& item) {
    std::unique_ptr<GildedRoseItem> gildedRoseItem;
    gildedRoseItem = createItem(item);
    gildedRoseItem->updateQuality();
    updateSellIn(item);
    if (item.sellIn < 0) {
        gildedRoseItem->updateExpired();
    }
}
