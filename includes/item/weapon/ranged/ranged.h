#ifndef RPG_INVENTORY_REVAMP_RANGED_H
#define RPG_INVENTORY_REVAMP_RANGED_H

#include "../weapon.h"

class Ranged : public Weapon {
protected:
  int projectileSpeed;
  int ammoCapacity;
  int spread;
  int rateOfFire;

public:
  Ranged(
    const std::string& name,
    const std::string& description,
    int value,
    int weight,
    ItemRarity rarity,

    // Weapon-specific attributes
    Influence influence,

    // Ranged-specific attributes
    int ammoCapacity
    ) : Weapon(name, description, value, weight, rarity, influence),
        ammoCapacity(ammoCapacity) {
      projectileSpeed = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(100, 200));
      rateOfFire = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(1, 10));
      spread = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(1, 10));
  }

  [[nodiscard]] int getProjectileSpeed() const;
  [[nodiscard]] int getAmmoCapacity() const;
  [[nodiscard]] int getSpread() const;
  [[nodiscard]] int getRateOfFire() const;
};

#endif //RPG_INVENTORY_REVAMP_RANGED_H
