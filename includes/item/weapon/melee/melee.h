#ifndef RPG_INVENTORY_REVAMP_MELEE_H
#define RPG_INVENTORY_REVAMP_MELEE_H

#include "../weapon.h"

enum class DamageType {
    BLUNT,
    SLASH,
    PIERCE,
};

class Melee : public Weapon {
  int length;
  int attackSpeed;
  DamageType damageType;

  public:
    Melee(
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
    ) : Weapon(name, description, value, weight, rarity, influence),
        length(length),
        damageType(damageType) {
      attackSpeed = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(10, 20));
    }

    [[nodiscard]] int getLength() const;
    [[nodiscard]] int getAttackSpeed() const;
    [[nodiscard]] DamageType getDamageType() const;
};

#endif //RPG_INVENTORY_REVAMP_MELEE_H
