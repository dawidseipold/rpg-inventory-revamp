#ifndef RPG_INVENTORY_REVAMP_WORLD_H
#define RPG_INVENTORY_REVAMP_WORLD_H

#include <vector>
#include <algorithm>
#include <memory>
#include "../container/chest/chest.h"


class World {
  std::vector<std::unique_ptr<Chest>> chests;
//  std::vector<Monster> monsters;
//  std::vector<NonPlayerCharacter> npcs;

  public:
  World() = default;

  //  Create
  void addChest(std::unique_ptr<Chest> chest) {
    chests.push_back(std::move(chest));
  };

  //  Read
  std::vector<std::unique_ptr<Chest>>& getChests() {
    return chests;
  };

  //  Delete
  void removeChest(const Chest& chest) {
//    chests.erase(std::remove(chests.begin(), chests.end(), chest), chests.end());

    for (auto it = chests.begin(); it != chests.end(); ++it) {
      if (**it == chest) {
        chests.erase(it);
        break;
      }
    }

  };
};

#endif //RPG_INVENTORY_REVAMP_WORLD_H
