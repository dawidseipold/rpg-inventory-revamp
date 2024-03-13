#include "../../includes/character/character-class.h"

[[maybe_unused]] std::string displayCharacterClass(CharacterClass characterClass) {
  switch (characterClass) {
    case CharacterClass::WARRIOR:
      return "Warrior";
    case CharacterClass::MAGE:
      return "Mage";
    case CharacterClass::RANGER:
      return "Ranger";
    case CharacterClass::CLERIC:
      return "Cleric";
  }
}