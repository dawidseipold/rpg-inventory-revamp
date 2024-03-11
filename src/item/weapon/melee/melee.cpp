#include "../../../../includes/item/weapon/melee/melee.h"

[[nodiscard]] std::pair<int, int> Melee::getDamageRange() const {
  return std::make_pair(minDamage, maxDamage);
}