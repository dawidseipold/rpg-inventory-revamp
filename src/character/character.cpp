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
  std::cout << std::format("Unused skill points: {0}", unusedSkillPoints) << std::endl;
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

CharacterClass Character::getClass() const {
  return characterClass;
}

Inventory& Character::getInventory() {
  return inventory;
}

void Character::useSkillPoints() {
  if (!unusedSkillPoints) {
    std::cout << "You don't have any skill points to spend." << std::endl;
    return;
  }

  std::cout << "You have " << unusedSkillPoints << " skill points to spend." << std::endl;

  Menu skillMenu("Skill Menu");

  skillMenu.addOption("Strength", [this]() {
    this->strength++;
    this->unusedSkillPoints--;
  });

  skillMenu.addOption("Dexterity", [this]() {
    this->dexterity++;
    this->unusedSkillPoints--;
  });

  skillMenu.addOption("Intelligence", [this]() {
    this->intelligence++;
    this->unusedSkillPoints--;
  });

  skillMenu.addOption("Luck", [this]() {
    this->luck++;
    this->unusedSkillPoints--;
  });

  skillMenu.display();
}

void Character::addExperience(int experienceToAdd) {
  this->experience += experienceToAdd;

  while (this->experience >= 100 * level) {
    this->experience -= 100 * level;
    level++;
    unusedSkillPoints += 2;
  }
}
