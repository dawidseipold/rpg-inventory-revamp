#include "../../includes/character/character.h"

void Character::setBaseStats() {
  switch (characterClass) {
    case CharacterClass::WARRIOR:
      health = LimitedStat(170, 200);
      mana = LimitedStat(20, 100);
      strength = LimitedStat(8, 10);
      dexterity = LimitedStat(6, 10);
      intelligence = LimitedStat(2, 10);
      luck = LimitedStat(4, 10);

      break;
    case CharacterClass::MAGE:
      health = LimitedStat(70, 200);
      mana = LimitedStat(80, 100);
      strength = LimitedStat(2, 10);
      dexterity = LimitedStat(3, 10);
      intelligence = LimitedStat(9, 10);
      luck = LimitedStat(6, 10);

      break;
    case CharacterClass::RANGER:
      health = LimitedStat(100, 200);
      mana = LimitedStat(30, 100);
      strength = LimitedStat(3, 10);
      dexterity = LimitedStat(8, 10);
      intelligence = LimitedStat(4, 10);
      luck = LimitedStat(5, 10);

      break;
    case CharacterClass::CLERIC:
      health = LimitedStat(140, 200);
      mana = LimitedStat(60, 100);
      strength = LimitedStat(5, 10);
      dexterity = LimitedStat(5, 10);
      intelligence = LimitedStat(5, 10);
      luck = LimitedStat(5, 6);

      break;
  }
}
