#pragma once

#include "Item.h"

class SulfurasItem {
    [[maybe_unused]] Item& item_;

public:
    explicit SulfurasItem(Item& item) : item_(item) {}

    void updateQuality() {}
};
