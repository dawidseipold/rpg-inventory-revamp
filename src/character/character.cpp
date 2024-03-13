#include "../../includes/character/character.h"

void Character::setBaseStats() {
  //  TODO: Create a method to set the base stats for each class
  switch (characterClass) {
    case CharacterClass::WARRIOR:
      health = LimitedStat(170, 200);
      mana = LimitedStat(20, 100);
      this->strength = 8;
      this->dexterity = 6;
      this->intelligence = 2;
      this->luck = 4;

      break;
    case CharacterClass::MAGE:
      health = LimitedStat(70, 200);
      mana = LimitedStat(80, 100);
      this->strength = 2;
      this->dexterity = 3;
      this->intelligence = 9;
      this->luck = 6;

      break;
    case CharacterClass::RANGER:
      health = LimitedStat(100, 200);
      mana = LimitedStat(30, 100);
      this->strength = 3;
      this->dexterity = 8;
      this->intelligence = 4;
      this->luck = 5;

      break;
    case CharacterClass::CLERIC:
      health = LimitedStat(140, 200);
      mana = LimitedStat(60, 100);
      this->strength = 5;
      this->dexterity = 5;
      this->intelligence = 5;
      this->luck = 5;

      break;
  }
}

void Character::displayCharacter() const {
  std::cout << std::format("Name: {0}", name) << std::endl;
  std::cout << std::format("Class: {0}", displayCharacterClass(characterClass)) << std::endl;
  std::cout << std::format("Level: {0}", level) << std::endl;
  std::cout << std::format("Experience: {0}", experience) << std::endl;
  std::cout << std::format("Gold: {0}", inventory.getGold()) << std::endl;
  std::cout << std::format("Health: {0}", health.getValue()) << std::endl;
  std::cout << std::format("Mana: {0}", mana.getValue()) << std::endl;
  std::cout << std::format("Strength: {0}", strength) << std::endl;
  std::cout << std::format("Dexterity: {0}", dexterity) << std::endl;
  std::cout << std::format("Intelligence: {0}", intelligence) << std::endl;
  std::cout << std::format("Luck: {0}", luck) << std::endl;
  std::cout << std::format("Carrying capacity: {0}/{1}", inventory.getCurrentWeight(), inventory.getMaxWeight()) << std::endl;
}

std::string Character::getName() const {
  return name;
}

Inventory Character::getInventory() {
  return inventory;
}
