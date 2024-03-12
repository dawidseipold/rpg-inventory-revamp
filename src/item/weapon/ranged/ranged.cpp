#include "../../../../includes/item/weapon/ranged/ranged.h"

[[nodiscard]] int Ranged::getProjectileSpeed() const {
  return projectileSpeed;
}

[[nodiscard]] int Ranged::getAmmoCapacity() const {
  return ammoCapacity;
}

[[nodiscard]] int Ranged::getSpread() const {
  return spread;
}

[[nodiscard]] int Ranged::getRateOfFire() const {
  return rateOfFire;
}
