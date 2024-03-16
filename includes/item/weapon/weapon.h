#ifndef RPG_INVENTORY_REVAMP_WEAPON_H
#define RPG_INVENTORY_REVAMP_WEAPON_H

#include <utility>

#include "../item.h"
#include "../influence.h"
#include "./stats-helpers.h"

class Weapon : public Item {
private:
  Influence influence;

protected:
  int accuracy;
  int minDamage;
  int maxDamage;

public:
  ~Weapon() override = default;

  Weapon() = default;

  Weapon(
    const std::string& name,
    const std::string& description,
    int value,
    int weight,
    ItemRarity rarity,

    // Weapon-specific attributes
    Influence influence
  ) : Item(name, description, value, weight, rarity),
    influence(influence) {
      accuracy = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(50, 100));
      minDamage = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(40, 120));
      maxDamage = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(160, 270));
  }

  [[nodiscard]] std::pair<int, int> getDamageRange() const;
  [[nodiscard]] int getAccuracy() const;
};

#endif //RPG_INVENTORY_REVAMP_WEAPON_H
