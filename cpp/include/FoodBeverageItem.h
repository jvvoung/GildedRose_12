#pragma once

#include "GildedRoseItem.h"

class FoodBeverageItem : public GildedRoseItem {
public:
    using GildedRoseItem::GildedRoseItem;

    void updateQuality() override { degradeTwice(); }

    void updateExpired() override { degradeTwice(); }

private:
    void degradeTwice() {
        static constexpr int minQuality = 0;
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
    }
};
