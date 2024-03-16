#ifndef RPG_INVENTORY_REVAMP_BLUNDERBUSS_H
#define RPG_INVENTORY_REVAMP_BLUNDERBUSS_H

#include "../ranged.h"

class Blunderbuss : public Ranged {
public:
  ~Blunderbuss() override = default;

  Blunderbuss() = default;

  explicit Blunderbuss(
    int ammoCapacity
  ) : Ranged(ammoCapacity) {}
};

#endif //RPG_INVENTORY_REVAMP_BLUNDERBUSS_H
