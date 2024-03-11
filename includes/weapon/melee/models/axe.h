#ifndef RPG_INVENTORY_REVAMP_AXE_H
#define RPG_INVENTORY_REVAMP_AXE_H

#include "../melee.h"

class Axe : public Melee {
public:
  Axe(
    const std::string& name,
    const std::string& description,
    int value,
    int weight,
    ItemRarity rarity,
    int minDamage,
    int maxDamage,
    int criticalRate,
    int criticalDamage,
    int accuracy,
    Influence influence,
    int range,
    int length,
    int attackSpeed,
    DamageType damageType
  ) : Melee(name, description, value, weight, rarity, minDamage, maxDamage, criticalRate, criticalDamage, accuracy, influence, range, length, attackSpeed, damageType) {}
};

#endif //RPG_INVENTORY_REVAMP_AXE_H
