#ifndef RPG_INVENTORY_REVAMP_CHARACTER_H
#define RPG_INVENTORY_REVAMP_CHARACTER_H

#include <iostream>
#include <utility>
#include <format>
#include "./limited-stat.h"
#include "./character-class.h"
#include "../container/inventory/inventory.h"

class Character {
  std::string name;
  LimitedStat health;
  LimitedStat mana;
  int strength{};
  int dexterity{};
  int intelligence{};
  int luck{};
  int experience;
  int level;
  CharacterClass characterClass;
  Inventory inventory;

  void setBaseStats();

public:
  Character() :
    health(0, 0),
    mana(0, 0),
    strength(0), dexterity(0),
    intelligence(0),
    luck(0),
    experience(0),
    level(0),
    characterClass(CharacterClass::WARRIOR),
    inventory("Inventory", 200) {
      setBaseStats();
  }

  Character(std::string name,
    CharacterClass characterClass) :
      name(std::move(name)),
      characterClass(characterClass),
      health(0, 0),
      mana(0, 0),
      inventory("Inventory", 200) {
        setBaseStats();

        level = 1;
        experience = 0;
  };

  void displayCharacter() const;

  [[nodiscard]] std::string getName() const;

  Inventory getInventory();
};

#endif //RPG_INVENTORY_REVAMP_CHARACTER_H
