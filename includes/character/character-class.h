#ifndef RPG_INVENTORY_REVAMP_CHARACTER_CLASS_H
#define RPG_INVENTORY_REVAMP_CHARACTER_CLASS_H

#include <iostream>

enum class CharacterClass {
  WARRIOR,
  MAGE,
  RANGER,
  CLERIC
};

[[maybe_unused]] std::string displayCharacterClass(CharacterClass characterClass);

#endif //RPG_INVENTORY_REVAMP_CHARACTER_CLASS_H
