#ifndef RPG_INVENTORY_REVAMP_HAMMER_H
#define RPG_INVENTORY_REVAMP_HAMMER_H

#include "../melee.h"

class Hammer : public Melee {
public:
  ~Hammer() override = default;

  Hammer () = default;

  explicit Hammer(
    int length,
    DamageType damageType
  ) : Melee(length, damageType) {

  }
};

#endif //RPG_INVENTORY_REVAMP_HAMMER_H
