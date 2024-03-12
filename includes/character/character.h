#ifndef RPG_INVENTORY_REVAMP_CHARACTER_H
#define RPG_INVENTORY_REVAMP_CHARACTER_H

#include <iostream>
#include <utility>
#include "./limited-stat.h"
#include "./character-class.h"

class Character {
  std::string name;
  LimitedStat health;
  LimitedStat mana;
  LimitedStat strength;
  LimitedStat dexterity;
  LimitedStat intelligence;
  LimitedStat luck;
  int experience;
  int gold;
  int level;
  CharacterClass characterClass;

public:
  Character(
    std::string  name,
    CharacterClass characterClass
  ) : name(std::move(name)),
      characterClass(characterClass),
      health(0, 0),
      mana(0, 0),
      strength(0, 0),
      dexterity(0, 0),
      intelligence(0, 0),
      luck(0, 0) {
        setBaseStats();

        level = 1;
        experience = 0;
        gold = 0;
  };

  void setBaseStats();
};

#endif //RPG_INVENTORY_REVAMP_CHARACTER_H
