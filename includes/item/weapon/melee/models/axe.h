#ifndef RPG_INVENTORY_REVAMP_AXE_H
#define RPG_INVENTORY_REVAMP_AXE_H

#include <random>
#include "../melee.h"

class Axe : public Melee {
public:
  Axe(
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

#endif //RPG_INVENTORY_REVAMP_AXE_H
