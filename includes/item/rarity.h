#ifndef RPG_INVENTORY_REVAMP_RARITY_H
#define RPG_INVENTORY_REVAMP_RARITY_H

enum class ItemRarity {
  COMMON,
  RARE,
  ENCHANTED,
  ANCIENT,
  MYTHICAL
};

[[nodiscard]] static ItemRarity &itemRarityToString(ItemRarity rarity) {
  switch(rarity) {
    case ItemRarity::COMMON:
      return (ItemRarity &) "Common";
    case ItemRarity::RARE:
      return (ItemRarity &) "Rare";
    case ItemRarity::ENCHANTED:
      return (ItemRarity &) "Enchanted";
    case ItemRarity::ANCIENT:
      return (ItemRarity &) "Ancient";
    case ItemRarity::MYTHICAL:
      return (ItemRarity &) "Mythical";
    default:
      return (ItemRarity &) "Unknown";
  }
}


#endif //RPG_INVENTORY_REVAMP_RARITY_H
