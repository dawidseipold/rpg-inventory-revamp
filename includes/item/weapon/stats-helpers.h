#ifndef RPG_INVENTORY_REVAMP_STATS_HELPERS_H
#define RPG_INVENTORY_REVAMP_STATS_HELPERS_H

#include <utility>
#include "../rarity.h"

int calculateMinDamage(ItemRarity rarity, std::pair<int, int> range);

#endif //RPG_INVENTORY_REVAMP_STATS_HELPERS_H
