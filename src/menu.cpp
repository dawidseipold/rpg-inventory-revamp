#include "../includes/menu.h"
#include <format>

int displayStartupMenu() {
  int choice;

  std::cout << "Welcome to the RPG Inventory Revamp!" << std::endl;
  std::cout << "1. Play" << std::endl;
  std::cout << "2. Quit" << std::endl;

  std::cin >> choice;

  return choice;
}

std::string setCharacterName() {
  std::string name;

  //  TOOD: Add character name checks
  std::cout << "Enter your name: ";
  std::cin >> name;

  std::cout << std::format("Hello there, {0}!", name) << std::endl;

  return name;
}

CharacterClass setCharacterClass() {
  int choice;

  std::cout << "Choose your class:" << std::endl;
  std::cout << "1. Warrior" << std::endl;
  std::cout << "2. Mage" << std::endl;
  std::cout << "3. Ranger" << std::endl;
  std::cout << "4. Cleric" << std::endl;

  std::cin >> choice;

  switch (choice) {
    case 1:
      std::cout << "You have chosen the Warrior class." << std::endl;

      return CharacterClass::WARRIOR;
    case 2:
      std::cout << "You have chosen the Mage class." << std::endl;

      return CharacterClass::MAGE;
    case 3:
      std::cout << "You have chosen the Ranger class." << std::endl;

      return CharacterClass::RANGER;
    case 4:
      std::cout << "You have chosen the Cleric class." << std::endl;

      return CharacterClass::CLERIC;

    default:
      std::cout << "Invalid choice. Please try again." << std::endl;

      return setCharacterClass();
  }
}

void displayMainMenu() {
  std::cout << "1. View inventory" << std::endl;
  std::cout << "2. View character" << std::endl;
  std::cout << "3. Quit" << std::endl;
}