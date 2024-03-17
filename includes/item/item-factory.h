#ifndef RPG_INVENTORY_REVAMP_ITEM_FACTORY_H
#define RPG_INVENTORY_REVAMP_ITEM_FACTORY_H

#include <map>
#include <functional>
#include <memory>
#include "item.h"
#include "weapon/ranged/models/blunderbuss.h"
#include "weapon/ranged/models/pistol.h"
#include "weapon/ranged/models/cannon.h"
#include "weapon/melee/models/axe.h"
#include "weapon/melee/models/hammer.h"
#include "weapon/melee/models/sword.h"
// Include other item types here

using ItemCreator = std::unique_ptr<Item> (*)();

class ItemFactory {
private:

public:
  ItemFactory() = default;

  static std::unique_ptr<Item> createItem(const std::string& model) {
    return itemCreators[model]();
  }

  static std::map<std::string, std::function<std::unique_ptr<Item>()>> itemCreators;
};

 std::map<std::string, std::function<std::unique_ptr<Item>()>> ItemFactory::itemCreators = {
  {"Blunderbuss", []() { return std::make_unique<Blunderbuss>(); }},
  {"Pistol", []() { return std::make_unique<Pistol>(); }},
  {"Cannon", []() { return std::make_unique<Cannon>(); }},
  {"Axe", []() { return std::make_unique<Axe>(); }},
  {"Hammer", []() { return std::make_unique<Hammer>(); }},
  {"Sword", []() { return std::make_unique<Sword>(); }},
};

#endif //RPG_INVENTORY_REVAMP_ITEM_FACTORY_H