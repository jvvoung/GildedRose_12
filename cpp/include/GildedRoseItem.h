#pragma once

#include "Item.h"

class GildedRoseItem {
protected:
    Item& item_;

public:
    explicit GildedRoseItem(Item& item) : item_(item) {}
    virtual ~GildedRoseItem() = default;

    virtual void updateQuality() = 0;

    virtual void updateExpired() {}
};
