#ifndef RPG_INVENTORY_REVAMP_MELEE_H
#define RPG_INVENTORY_REVAMP_MELEE_H

#include "../weapon.h"

enum class DamageType {
    BLUNT,
    SLASH,
    PIERCE,
};

class Melee : public Weapon {
  int length{};
  int attackSpeed{};
  DamageType damageType{};

  public:
    ~Melee() override = default;

    Melee () = default;

    explicit Melee(
      int length,
      DamageType damageType
    ) : length(length),
        damageType(damageType) {
      attackSpeed = getRandomNumberFromRangeBasedOnRarity(this->rarity, std::pair<int, int>(10, 20));
    }

    [[nodiscard]] int getLength() const;
    [[nodiscard]] int getAttackSpeed() const;
    [[nodiscard]] DamageType getDamageType() const;
};

#endif //RPG_INVENTORY_REVAMP_MELEE_H
