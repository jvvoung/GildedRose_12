#include "GildedRose.h"

#include "AgedBrieItem.h"
#include "BackstagePassItem.h"
#include "FoodBeverageItem.h"
#include "GildedRoseItem.h"
#include "NormalItem.h"
#include "SulfurasItem.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

std::unique_ptr<GildedRoseItem> GildedRose::createItem(Item& item) {
    if (item.name == AGED_BRIE) {
        return std::make_unique<AgedBrieItem>(item);
    }
    if (item.name == BACKSTAGE_PASS) {
        return std::make_unique<BackstagePassItem>(item);
    }
    if (item.name == SULFURAS) {
        return std::make_unique<SulfurasItem>(item);
    }
    if (item.name.find("[F&B]") != std::string::npos) {
        return std::make_unique<FoodBeverageItem>(item);
    }
    return std::make_unique<NormalItem>(item);
}

void GildedRose::updateSellIn(Item& item) {
    if (item.name != SULFURAS) {
        item.sellIn = item.sellIn - 1;
    }
}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        auto gildedItem = createItem(item);
        gildedItem->updateQuality();
        updateSellIn(item);
        if (item.sellIn < 0) {
            gildedItem->updateExpired();
        }
    }
}
