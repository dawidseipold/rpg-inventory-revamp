#include "../../../includes/item/weapon/stats-helpers.h"
#include "../../../includes/item/rarity.h"

#include <random>

std::pair<double, double> getMultipliersBasedOnRarity(ItemRarity rarity) {
  switch (rarity) {
    case ItemRarity::COMMON:
      return {0.0, 0.8};
    case ItemRarity::RARE:
      return {0.2, 0.6};
    case ItemRarity::ENCHANTED:
      return {0.4, 0.4};
    case ItemRarity::ANCIENT:
      return {0.6, 0.2};
    case ItemRarity::MYTHICAL:
      return {0.8, 0.0};
  }
}

int getRandomNumberFromRangeBasedOnRarity(ItemRarity rarity, std::pair<int, int> range) {
  auto [minMultiplier, maxMultiplier] = getMultipliersBasedOnRarity(rarity);

  double min = range.first + ((range.second - range.first) * minMultiplier);
  double max = range.second - ((range.second - range.first) * maxMultiplier);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(static_cast<int>(min), static_cast<int>(max));

  return dist(gen);
}
