#ifndef RPG_INVENTORY_REVAMP_INVENTORY_H
#define RPG_INVENTORY_REVAMP_INVENTORY_H

#include <utility>

#include "../container.h"
#include "../../character/character.h"

class Inventory : public Container {
  //   Inventory-specific attributes
  int gold;

public:
  Inventory(
    std::string name,
    int maxWeight
  ) : Container(std::move(name), maxWeight) {
    const std::vector<Item>& items = {};
    currentWeight = 0;
    this->gold = 0;
  }

  [[nodiscard]] int getGold() const {
    return gold;
  }
};

#endif //RPG_INVENTORY_REVAMP_INVENTORY_H
