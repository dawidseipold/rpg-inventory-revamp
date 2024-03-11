#ifndef RPG_INVENTORY_REVAMP_PISTOL_H
#define RPG_INVENTORY_REVAMP_PISTOL_H

#include "../ranged.h"

class Pistol : public Ranged {
private:

public:
  Pistol(
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
    int rateOfFire,
    int projectileSpeed,
    int ammoCapacity,
    int spread
  ) : Ranged(name, description, value, weight, rarity, minDamage, maxDamage, criticalRate, criticalDamage, accuracy, influence, range, rateOfFire, projectileSpeed, ammoCapacity, spread) {}
};

#endif //RPG_INVENTORY_REVAMP_PISTOL_H