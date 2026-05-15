#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

void GildedRose::updateAgedBrieBeforeSellIn(Item& item) {
    if (item.quality < MAX_QUALITY) {
        item.quality = item.quality + 1;
    }
}

void GildedRose::updateBackstagePassBeforeSellIn(Item& item) {
    if (item.quality < MAX_QUALITY) {
        item.quality = item.quality + 1;
    }
    if (item.sellIn < 11) {
        if (item.quality < MAX_QUALITY) {
            item.quality = item.quality + 1;
        }
    }
    if (item.sellIn < 6) {
        if (item.quality < MAX_QUALITY) {
            item.quality = item.quality + 1;
        }
    }
}

void GildedRose::updateSulfurasBeforeSellIn(Item&) {}

void GildedRose::updateNormalItemBeforeSellIn(Item& item) {
    if (item.quality > MIN_QUALITY) {
        item.quality = item.quality - 1;
    }
}

void GildedRose::updateSellIn(Item& item) {
    if (item.name != SULFURAS) {
        item.sellIn = item.sellIn - 1;
    }
}

void GildedRose::updateExpiredItem(Item& item) {
    if (item.name == AGED_BRIE) {
        if (item.quality < MAX_QUALITY) {
            item.quality = item.quality + 1;
        }
    } else if (item.name == BACKSTAGE_PASS) {
        item.quality = item.quality - item.quality;
    } else if (item.name != SULFURAS && item.quality > MIN_QUALITY) {
        item.quality = item.quality - 1;
    }
}

void GildedRose::updateQuality() {
    for (size_t i = 0; i < items.size(); i++) {
        Item& item = items[i];

        if (item.name == AGED_BRIE) {
            updateAgedBrieBeforeSellIn(item);
        } else if (item.name == BACKSTAGE_PASS) {
            updateBackstagePassBeforeSellIn(item);
        } else if (item.name == SULFURAS) {
            updateSulfurasBeforeSellIn(item);
        } else {
            updateNormalItemBeforeSellIn(item);
        }

        updateSellIn(item);

        if (item.sellIn < 0) {
            updateExpiredItem(item);
        }
    }
}
