#include "../../../includes/item/weapon/stats-helpers.h"

#include <random>
#include <limits>
#include <stdexcept>

int calculateMinDamage (ItemRarity rarity, std::pair<int, int> range) {
  if (range.first > range.second) {
    throw std::invalid_argument("Invalid range: minimal damage is greater than maximal damage.");
  }

  double rarityMultiplier;

  switch (rarity) {
    case ItemRarity::COMMON:
      rarityMultiplier = 0.2;

      break;
    case ItemRarity::RARE:
      rarityMultiplier = 0.4;

      break;
    case ItemRarity::ENCHANTED:
      rarityMultiplier = 0.6;

      break;
    case ItemRarity::ANCIENT:
      rarityMultiplier = 0.8;

      break;
    case ItemRarity::MYTHICAL:
      rarityMultiplier = 1.0;

      break;
  }

  double damageRange = (range.second - range.first) * rarityMultiplier;

  std::random_device randomDevice;
  std::mt19937 gen(randomDevice());
  std::uniform_int_distribution<int> distribution(range.first, static_cast<int>(range.first + damageRange));

  int minDamage = distribution(gen);

  return std::max(minDamage, range.first);
}