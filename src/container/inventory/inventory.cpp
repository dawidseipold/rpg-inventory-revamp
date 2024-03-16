//
// Created by glowabyk on 3/15/2024.
//
#include "../../../includes/container/inventory/inventory.h"

Inventory Inventory::getProperties() {
  return *this;
}

[[maybe_unused]] [[nodiscard]] int Inventory::getGold() const {
  return gold;
}

