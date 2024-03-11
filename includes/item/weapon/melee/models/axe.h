#ifndef RPG_INVENTORY_REVAMP_AXE_H
#define RPG_INVENTORY_REVAMP_AXE_H

#include <random>
#include "../melee.h"
#include "../../stats-helpers.h"

class Axe : public Melee {
public:
  Axe(
    const std::string& name,
    const std::string& description,
    int value,
    int weight,
    ItemRarity rarity,
    int criticalRate,
    int criticalDamage,
    int accuracy,
    Influence influence,
    int range,
    int length,
    int attackSpeed,
    DamageType damageType
  ) : Melee(name, description, value, weight, rarity, minDamage, maxDamage, criticalRate, criticalDamage, accuracy, influence, range, length, attackSpeed, damageType) {
    minDamage = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(40, 120));
    maxDamage = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(160, 270));
  }
};

#endif //RPG_INVENTORY_REVAMP_AXE_H
