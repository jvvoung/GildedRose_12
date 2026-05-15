#pragma once

#include "GildedRoseItem.h"

class AgedBrieItem : public GildedRoseItem {
public:
    using GildedRoseItem::GildedRoseItem;

    void updateQuality() override {
        static constexpr int maxQuality = 50;
        if (item_.quality < maxQuality) {
            item_.quality = item_.quality + 1;
        }
    }

    void updateExpired() override {
        static constexpr int maxQuality = 50;
        if (item_.quality < maxQuality) {
            item_.quality = item_.quality + 1;
        }
    }
};
