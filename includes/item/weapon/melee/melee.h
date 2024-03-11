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
      int minDamage,
      int maxDamage,
      int criticalRate,
      int criticalDamage,
      int accuracy,
      Influence influence,
      int range,

      // Melee-specific attributes
      int length,
      int attackSpeed,
      DamageType damageType
    ) : Weapon(name, description, value, weight, rarity, minDamage, maxDamage, criticalRate, criticalDamage, accuracy, influence, range),
        length(length),
        attackSpeed(attackSpeed),
        damageType(damageType) {}

  [[nodiscard]] std::pair<int, int> getDamageRange() const;
};

#endif //RPG_INVENTORY_REVAMP_MELEE_H
