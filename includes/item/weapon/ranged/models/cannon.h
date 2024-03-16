#ifndef RPG_INVENTORY_REVAMP_CANNON_H
#define RPG_INVENTORY_REVAMP_CANNON_H

#include "../ranged.h"

class Cannon : public Ranged {
public:
  ~Cannon() override = default;

  Cannon() = default;

  explicit Cannon(
    int ammoCapacity
  ) : Ranged(ammoCapacity) {}
};

#endif //RPG_INVENTORY_REVAMP_CANNON_H
