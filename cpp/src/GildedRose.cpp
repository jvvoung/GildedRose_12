#include "GildedRose.h"

#include "AgedBrieItem.h"
#include "BackstagePassItem.h"
#include "NormalItem.h"
#include "SulfurasItem.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

void GildedRose::updateSellIn(Item& item) {
    if (item.name != SULFURAS) {
        item.sellIn = item.sellIn - 1;
    }
}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        if (item.name == AGED_BRIE) {
            AgedBrieItem{item}.updateQuality();
        } else if (item.name == BACKSTAGE_PASS) {
            BackstagePassItem{item}.updateQuality();
        } else if (item.name == SULFURAS) {
            SulfurasItem{item}.updateQuality();
        } else {
            NormalItem{item}.updateQuality();
        }

        updateSellIn(item);

        if (item.sellIn < 0) {
            if (item.name == AGED_BRIE) {
                AgedBrieItem{item}.updateExpired();
            } else if (item.name == BACKSTAGE_PASS) {
                BackstagePassItem{item}.updateExpired();
            } else if (item.name != SULFURAS) {
                NormalItem{item}.updateExpired();
            }
        }
    }
}
