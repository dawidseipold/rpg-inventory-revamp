#ifndef RPG_INVENTORY_REVAMP_CHARACTER_H
#define RPG_INVENTORY_REVAMP_CHARACTER_H

#include <iostream>
#include <utility>
#include <format>
#include "./limited-stat.h"
#include "./character-class.h"
#include "../container/inventory/inventory.h"
#include "../../includes/menu/menu.h"

class Character {
  std::string name;
  LimitedStat health;
  LimitedStat mana;
  int strength{};
  int dexterity{};
  int intelligence{};
  int luck{};
  int experience{};
  int level{};
  int unusedSkillPoints{};
  CharacterClass characterClass;
  Inventory inventory{};

  void setBaseStats();

public:
  Character() = default;

  Character(
    std::string name,
    CharacterClass characterClass,
    Inventory inventory
  ) :
    name(std::move(name)),
    characterClass(characterClass),
    health(0, 0),
    mana(0, 0),
    inventory(std::move(inventory)) {
      setBaseStats();

      level = 1;
      experience = 0;
      unusedSkillPoints = 0;
    };

  void displayCharacter() const;

  [[nodiscard]] std::string getName() const;
  [[nodiscard]] CharacterClass getClass() const;

  Inventory& getInventory();

  void useSkillPoints();

  void addExperience(int experienceToAdd);
};

#endif //RPG_INVENTORY_REVAMP_CHARACTER_H
