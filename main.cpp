#include <iostream>
#include <format>
#include "includes/item/rarity.h"
#include "includes/item/weapon/stats-helpers.h"
#include "includes/item/weapon/melee/models/axe.h"


int main() {
  Axe axe(
    "Axe",
    "A simple axe",
    100,
    10,
    ItemRarity::MYTHICAL,
    10,
    20,
    80,
    Influence::NONE,
    1,
    1,
    1,
    DamageType::SLASH
  );

  std::pair<int, int> damageRange = axe.getDamageRange();

  std::cout << std::format("Minimal damage: {0}, Maximum damage: {1}", damageRange.first, damageRange.second) << std::endl;

  return 0;
}
