#ifndef RPG_INVENTORY_REVAMP_AXE_H
#define RPG_INVENTORY_REVAMP_AXE_H

#include <random>
#include "../melee.h"

class Axe : public Melee {
public:
  ~Axe() override = default;

  Axe () = default;

  explicit Axe(
    int length,
    DamageType damageType
  ) : Melee(length, damageType) {

  }
};

#endif //RPG_INVENTORY_REVAMP_AXE_H
