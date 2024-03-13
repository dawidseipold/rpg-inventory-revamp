#ifndef RPG_INVENTORY_REVAMP_ITEM_H
#define RPG_INVENTORY_REVAMP_ITEM_H

#include <iostream>
#include <utility>
#include "rarity.h"

class Item {
  std::string name;
  std::string description;
  int value;
  int weight;

protected:
  ItemRarity rarity;
public:
    Item(
      std::string name,
      std::string description,
      int value,
      int weight,
      ItemRarity rarity
    ) : name(std::move(name)),
        description(std::move(description)),
        value(value),
        weight(weight),
        rarity(rarity) {};

    bool operator==(const Item& other) const {
      return name == other.name &&
      description == other.description &&
      value == other.value &&
      weight == other.weight &&
      rarity == other.rarity;
    }

    [[nodiscard]] const std::string& getName() const {
      return name;
    }

    [[nodiscard]] const std::string& getDescription() const {
      return description;
    }

    [[nodiscard]] int getValue() const {
      return value;
    }

    [[nodiscard]] int getWeight() const {
      return weight;
    }

    [[nodiscard]] ItemRarity getRarity() const {
      return rarity;
    }
};

#endif //RPG_INVENTORY_REVAMP_ITEM_H
