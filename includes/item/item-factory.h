//#ifndef RPG_INVENTORY_REVAMP_ITEM_FACTORY_H
//#define RPG_INVENTORY_REVAMP_ITEM_FACTORY_H
//
//#include "item.h"
//#include "weapon/melee/models/axe.h"
//#include "weapon/melee/models/hammer.h"
//#include "weapon/melee/models/sword.h"
//#include "weapon/ranged/models/pistol.h"
//#include "weapon/ranged/models/cannon.h"
//#include "weapon/ranged/models/blunderbuss.h"
//#include <iostream>
//#include <memory>
//#include <map>
////
////class ItemFactory {
////public:
////  static std::unique_ptr<Item>
////  createItem(const std::string &category, const std::string &subCategory, const std::string &model,
////             const std::map<std::string, std::string>& map) {
////    if (category == "Weapon") {
////      if (subCategory == "Melee") {
////        if (model == "Axe") {
////          return std::make_unique<Axe>();
////        }
////
////        if (model == "Hammer") {
////          return std::make_unique<Hammer>();
////        }
////
////        if (model == "Sword") {
////          return std::make_unique<Sword>();
////        }
////      }
////
////      if (subCategory == "Ranged") {
////        if (model == "Blunderbuss") {
////          return std::make_unique<Blunderbuss>();
////        }
////
////        if (model == "Cannon") {
////          return std::make_unique<Cannon>();
////        }
////
////        if (model == "Pistol") {
////          return std::make_unique<Pistol>();
////        }
////      }
////    }
////
////    throw std::runtime_error("Invalid category or model");
////  }
////
////  static std::vector<std::pair<std::string, std::string>>
////  getConstructorParameters(const std::basic_string<char>& string, const std::basic_string<char>& basicString,
////                           const std::basic_string<char>& string1) {
////    return {
////            {"name",         "string"},
////            {"description",  "string"},
////            {"value",        "int"},
////            {"weight",       "int"},
////            {"rarity",       "ItemRarity"},
////            {"influence",    "Influence"},
////            {"accuracy",     "int"},
////            {"minDamage",    "int"},
////            {"maxDamage",    "int"},
////            {"ammoCapacity", "int"},
////            {"length",       "int"},
////            {"attackSpeed",  "int"},
////            {"damageType",   "DamageType"}
////    };
////  };
////
////  static std::map<std::string, std::map<std::string, std::vector<std::string>>> getItems() {
////    return
////      {
////        {
////        "Weapon", {
////            {"Melee", {"Axe", "Hammer", "Sword"}},
////            {"Ranged", {"Blunderbuss", "Cannon", "Pistol"}}
////          }
////        }
////      };
////  }
////};
////
//
//
//class ItemFactory {
//public:
//  static std::unique_ptr<Item>
//  createItem(const std::string &category, const std::string &subCategory, const std::string &model,
//             const std::map<std::string, std::string>& parameters) {
//    if (category == "Weapon") {
//      if (subCategory == "Melee") {
//        if (model == "Axe") {
//          return std::make_unique<Axe>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//
//        if (model == "Hammer") {
//          return std::make_unique<Hammer>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//
//        if (model == "Sword") {
//          return std::make_unique<Sword>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//      }
//
//      if (subCategory == "Ranged") {
//        if (model == "Blunderbuss") {
//          return std::make_unique<Blunderbuss>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//
//        if (model == "Cannon") {
//          return std::make_unique<Cannon>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//
//        if (model == "Pistol") {
//          return std::make_unique<Pistol>(parameters.at("name"), std::stoi(parameters.at("weight")));
//        }
//      }
//    }
//
//    throw std::runtime_error("Invalid category or model");
//  }
//};
//
//#endif //RPG_INVENTORY_REVAMP_ITEM_FACTORY_H
