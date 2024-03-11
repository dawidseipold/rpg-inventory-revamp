#ifndef RPG_INVENTORY_REVAMP_RANGED_H
#define RPG_INVENTORY_REVAMP_RANGED_H

#include "../weapon.h"

class Ranged : public Weapon {
  int rateOfFire;
  int projectileSpeed;
  int ammoCapacity;
  int spread;

public:
  Ranged(
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

    // Ranged-specific attributes
    int rateOfFire,
    int projectileSpeed,
    int ammoCapacity,
    int spread
    ) : Weapon(name, description, value, weight, rarity, minDamage, maxDamage, criticalRate, criticalDamage, accuracy, influence, range),
        rateOfFire(rateOfFire),
        projectileSpeed(projectileSpeed),
        ammoCapacity(ammoCapacity),
        spread(spread) {}
};

#endif //RPG_INVENTORY_REVAMP_RANGED_H
