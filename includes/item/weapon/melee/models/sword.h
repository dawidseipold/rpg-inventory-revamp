#ifndef RPG_INVENTORY_REVAMP_SWORD_H
#define RPG_INVENTORY_REVAMP_SWORD_H

#include "../melee.h"

class Sword : public Melee {
public:
  ~Sword() override = default;

  Sword () = default;

  explicit Sword(
    int length,
    DamageType damageType
  ) : Melee(length, damageType) {
  }
};

#endif //RPG_INVENTORY_REVAMP_SWORD_H
