#pragma once

#include "Item.h"

class AgedBrieItem {
    Item& item_;

public:
    explicit AgedBrieItem(Item& item) : item_(item) {}

    void updateQuality() {
        static constexpr int maxQuality = 50;
        if (item_.quality < maxQuality) {
            item_.quality = item_.quality + 1;
        }
    }

    void updateExpired() {
        static constexpr int maxQuality = 50;
        if (item_.quality < maxQuality) {
            item_.quality = item_.quality + 1;
        }
    }
};
