#ifndef RPG_INVENTORY_REVAMP_ITEM_H
#define RPG_INVENTORY_REVAMP_ITEM_H

#include <iostream>
#include <utility>

enum class ItemRarity {
  COMMON,
  RARE,
  ENCHANTED,
  ANCIENT,
  MYTHICAL
};

class Item {
  std::string name;
  std::string description;
  int value;
  int weight;
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
        rarity(rarity) {}

    [[nodiscard]] const std::string& getName() const {
      return name;
    }
};

#endif //RPG_INVENTORY_REVAMP_ITEM_H
