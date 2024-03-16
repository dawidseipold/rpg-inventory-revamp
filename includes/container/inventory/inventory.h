#ifndef RPG_INVENTORY_REVAMP_INVENTORY_H
#define RPG_INVENTORY_REVAMP_INVENTORY_H

#include <utility>
#include "../container.h"

class Inventory : public Container {
  //   Inventory-specific attributes
  int gold{};

public:
  Inventory () = default;

  Inventory(
    std::string name,
    int maxWeight
  ) : Container(std::move(name), maxWeight) {
    const std::vector<Item>& items = {};
    currentWeight = 0;
    gold = 0;
  }

  Inventory getProperties();

  [[maybe_unused]] [[nodiscard]] int getGold() const;
};

#endif //RPG_INVENTORY_REVAMP_INVENTORY_H
