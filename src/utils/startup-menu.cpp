#include "../../includes/menu/menu.h"
#include "../../includes/utils/startup-menu.h"
#include "../../includes/character/character.h"
#include "../../includes/helpers/input.h"

void displayNewGame(Character* character) {
  std::cout << "Welcome to the game!" << std::endl;

  auto name = getValidInput<std::string>("Choose your name: ");
  Menu subMenu("Choose your class...");

  subMenu.addOption("Warrior", [&name, &character]() {
    *character = *new Character(name, CharacterClass::WARRIOR);
  });

  subMenu.addOption("Mage", [&name, &character]() {
    *character = *new Character(name, CharacterClass::MAGE);
  });

  subMenu.addOption("Ranger", [&name, &character]() {
    *character = *new Character(name, CharacterClass::RANGER);
  });

  subMenu.addOption("Cleric", [&name, &character]() {
    *character = *new Character(name, CharacterClass::CLERIC);
  });

  subMenu.Display();
}

void displayStartupMenu(Character* character) {
  Menu startMenu("Main Menu");

  startMenu.addOption("New Game", [&character](){
    displayNewGame(character);
  });

  startMenu.addOption("Load Game", [](){ std::cout << "Load game!" << std::endl; });
  startMenu.addOption("Exit", [](){ std::cout << "Goodbye!" << std::endl; return 0; });

  startMenu.Display();
}