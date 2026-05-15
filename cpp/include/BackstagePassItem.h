#pragma once

#include "GildedRoseItem.h"

class BackstagePassItem : public GildedRoseItem {
public:
    using GildedRoseItem::GildedRoseItem;

    void updateQuality() override {
        static constexpr int maxQuality = 50;
        if (item_.quality < maxQuality) {
            item_.quality = item_.quality + 1;
        }
        if (item_.sellIn < 11) {
            if (item_.quality < maxQuality) {
                item_.quality = item_.quality + 1;
            }
        }
        if (item_.sellIn < 6) {
            if (item_.quality < maxQuality) {
                item_.quality = item_.quality + 1;
            }
        }
    }

    void updateExpired() override { item_.quality = item_.quality - item_.quality; }
};
