#pragma once

#include "Item.h"

class NormalItem {
    Item& item_;

public:
    explicit NormalItem(Item& item) : item_(item) {}

    void updateQuality() {
        static constexpr int minQuality = 0;
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
    }

    void updateExpired() {
        static constexpr int minQuality = 0;
        if (item_.quality > minQuality) {
            item_.quality = item_.quality - 1;
        }
    }
};
