#ifndef RPG_INVENTORY_REVAMP_CONTAINER_H
#define RPG_INVENTORY_REVAMP_CONTAINER_H

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include "../item/item.h"

class Container {
  int maxWeight;
  std::vector<Item> items;

protected:
  std::string name;

  int currentWeight;
public:
  Container(
    std::string name,
    int maxWeight
  ) : name(std::move(name)), maxWeight(maxWeight) {
    currentWeight = 0;
  }

  void addItem(const Item& item) {
    if (currentWeight + item.getWeight() <= maxWeight) {
      currentWeight += item.getWeight();
      items.push_back(item);
    } else {
      std::cout << "The container is full!" << std::endl;
    }
  }

  void removeItem(const Item& item) {
    auto itemToRemove = std::remove(items.begin(), items.end(), item);

    items.erase(itemToRemove, items.end());

    currentWeight -= item.getWeight();
  };

  void setMaxWeight(int newMaxWeight) {
    Container::maxWeight = newMaxWeight;
  };

  [[maybe_unused]] [[nodiscard]] const std::vector<Item>& getItems() const {
    return items;
  };

  [[maybe_unused]] [[nodiscard]] int getCurrentWeight() const {
    return currentWeight;
  };

  [[maybe_unused]] [[nodiscard]] int getMaxWeight() const {
    return maxWeight;
  };

  [[maybe_unused]] [[nodiscard]] std::string getName() {
    return name;
  };
};

#endif //RPG_INVENTORY_REVAMP_CONTAINER_H
