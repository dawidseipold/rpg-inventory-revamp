#include "../../../includes/item/weapon/weapon.h"

[[nodiscard]] std::pair<int, int> Weapon::getDamageRange() const {
  return std::make_pair(minDamage, maxDamage);
}

[[nodiscard]] int Weapon::getAccuracy() const {
  return accuracy;
}
