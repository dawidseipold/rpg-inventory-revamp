#include <iostream>
#include <format>
#include "includes/item/rarity.h"
#include "includes/item/weapon/stats-helpers.h"


int main() {
  std::pair<int, int> minDamageRange(10, 40);

  int minDamage = calculateMinDamage(ItemRarity::COMMON, minDamageRange);

  std::cout << std::format("Minimal damage: {}", minDamage) << std::endl;

    return 0;
}
