#pragma once

#include "GildedRoseItem.h"

class NormalItem : public GildedRoseItem {
public:
    using GildedRoseItem::GildedRoseItem;

    void updateQuality() override {
        static constexpr int minQuality = 0;
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
    }

    void updateExpired() override {
        static constexpr int minQuality = 0;
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
    }
};
