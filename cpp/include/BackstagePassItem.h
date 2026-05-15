#pragma once

#include "Item.h"

class BackstagePassItem {
    Item& item_;

public:
    explicit BackstagePassItem(Item& item) : item_(item) {}

    void updateQuality() {
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

    void updateExpired() { item_.quality = item_.quality - item_.quality; }
};
