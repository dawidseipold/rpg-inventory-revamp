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
    virtual ~Item() = default;
    
    Item () = default;

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

    // Read
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] const std::string& getDescription() const;
    [[nodiscard]] int getValue() const;
    [[nodiscard]] int getWeight() const;
    [[nodiscard]] ItemRarity getRarity() const;

    void displayProperties() const;

    // Update
    void setName(const std::string& newName);
    void setDescription(const std::string& newDescription);
    void setValue(int newValue);
    void setWeight(int newWeight);
    void setRarity(ItemRarity newRarity);
};

#endif //RPG_INVENTORY_REVAMP_ITEM_H
