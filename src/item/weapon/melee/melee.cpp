#include "../../../../includes/item/weapon/melee/melee.h"

[[nodiscard]] int Melee::getLength() const {
  return length;
}

[[nodiscard]] int Melee::getAttackSpeed() const {
  return attackSpeed;
}

[[nodiscard]] DamageType Melee::getDamageType() const {
  return damageType;
}
