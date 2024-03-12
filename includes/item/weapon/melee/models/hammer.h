#ifndef RPG_INVENTORY_REVAMP_HAMMER_H
#define RPG_INVENTORY_REVAMP_HAMMER_H

#include "../melee.h"

class Hammer : public Melee {
public:
  Hammer(
    const std::string& name,
    const std::string& description,
    int value,
    int weight,
    ItemRarity rarity,

    // Weapon-specific attributes
    Influence influence,

    // Melee-specific attributes
    int length,
    DamageType damageType
  ) : Melee(name, description, value, weight, rarity, influence, length, damageType) {

  }
};

#endif //RPG_INVENTORY_REVAMP_HAMMER_H
