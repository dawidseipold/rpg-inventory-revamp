#ifndef RPG_INVENTORY_REVAMP_CHEST_H
#define RPG_INVENTORY_REVAMP_CHEST_H

#include "../container.h"

class Chest : public Container {
  //  Chest-specific attributes
  std::pair <int, int> coordinates;

public:
  //  Comparison operator
  bool operator==(const Chest& chest) const {
    return name == chest.name;
  }

  Chest(
    std::string name,
    int maxWeight,
    std::pair <int, int> coordinates
  ) : Container(std::move(name), maxWeight), coordinates(coordinates) {
    const std::vector<Item>& items = {};
    currentWeight = 0;
  }

  void displayProperties() const;

  [[nodiscard]] std::pair<int, int> getCoordinates() const;

  void setName(const std::string& newName);
};

#endif //RPG_INVENTORY_REVAMP_CHEST_H
