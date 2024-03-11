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

#endif //RPG_INVENTORY_REVAMP_HAMMER_H
