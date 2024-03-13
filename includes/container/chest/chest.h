#ifndef RPG_INVENTORY_REVAMP_CHEST_H
#define RPG_INVENTORY_REVAMP_CHEST_H

#include "../container.h"

class Chest : public Container {
  //   Chest-specific attributes
  std::pair <int, int> coordinates;

public:
  Chest(
    std::string name,
    int maxWeight,
    std::pair <int, int> coordinates
  ) : Container(std::move(name), maxWeight), coordinates(coordinates) {
    const std::vector<Item>& items = {};
    currentWeight = 0;
  }
};

#endif //RPG_INVENTORY_REVAMP_CHEST_H
