#ifndef RPG_INVENTORY_REVAMP_PISTOL_H
#define RPG_INVENTORY_REVAMP_PISTOL_H

#include <memory>
#include <map>
#include <any>
#include "../ranged.h"

class Pistol : public Ranged {
public:
  ~Pistol() override = default;

  Pistol() = default;

  explicit Pistol(
    int ammoCapacity
  ) : Ranged(ammoCapacity) {}
};

#endif //RPG_INVENTORY_REVAMP_PISTOL_H
