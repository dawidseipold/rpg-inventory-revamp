#ifndef RPG_INVENTORY_REVAMP_WEAPON_H
#define RPG_INVENTORY_REVAMP_WEAPON_H

#include <utility>

#include "../item.h"
#include "../influence.h"

class Weapon : public Item {
  int criticalRate;
  int criticalDamage;
  int accuracy;
  Influence influence;
  int range;

protected:
  int minDamage;
  int maxDamage;
public:
    Weapon(
      const std::string& name,
      const std::string& description,
      int value,
      int weight,
      ItemRarity rarity,

      // Weapon-specific attributes
      int minDamage,
      int maxDamage,
      int criticalRate,
      int criticalDamage,
      int accuracy,
      Influence influence,
      int range
    ) : Item(name, description, value, weight, rarity),
        minDamage(minDamage),
        maxDamage(maxDamage),
        criticalRate(criticalRate),
        criticalDamage(criticalDamage),
        accuracy(accuracy),
        influence(influence),
        range(range) {}
};

#endif //RPG_INVENTORY_REVAMP_WEAPON_H
