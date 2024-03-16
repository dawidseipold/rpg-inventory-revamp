#ifndef RPG_INVENTORY_REVAMP_CONTAINER_H
#define RPG_INVENTORY_REVAMP_CONTAINER_H

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include "../item/item.h"

class Container {
  std::vector<Item> items;

protected:
  std::string name;

  int currentWeight{};
  int maxWeight{};
public:
  Container() = default;

  Container(
    std::string name,
    int maxWeight
  ) : name(std::move(name)), maxWeight(maxWeight) {
    currentWeight = 0;
  }

  //  Create
  void addItem(const Item& item);

  //  Read
  [[maybe_unused]] [[nodiscard]] const std::vector<Item>& getItems() const;
  [[maybe_unused]] [[nodiscard]] int getCurrentWeight() const;
  [[maybe_unused]] [[nodiscard]] int getMaxWeight() const;
  [[maybe_unused]] [[nodiscard]] std::string getName();

  void displayItems() const;

  //  Update
  void setMaxWeight(int newMaxWeight);

  //  Delete
  void removeItem(const Item& item);
};

#endif //RPG_INVENTORY_REVAMP_CONTAINER_H
