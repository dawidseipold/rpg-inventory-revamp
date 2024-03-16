#include "../../includes/menu/menu.h"
#include "../../includes/utils/startup-menu.h"
#include "../../includes/character/character.h"
#include "../../includes/helpers/input.h"

#include <format>

Character displayNewGameAndGetCharacter() {
  std::cout << "Welcome to the game!" << std::endl;

  auto name = getValidInput<std::string>("Choose your name: ");
  Menu subMenu("Choose your class...");

  Inventory inventory(std::format("{}'s Inventory", name), 200);

  Character character;

  subMenu.addOption("Warrior", [&name, &inventory, &character]() {
    character = Character(name, CharacterClass::WARRIOR, inventory);
  });

  subMenu.addOption("Mage", [&name, &inventory, &character]() {
    character = Character(name, CharacterClass::MAGE, inventory);
  });

  subMenu.addOption("Ranger", [&name, &inventory, &character]() {
    character = Character(name, CharacterClass::RANGER, inventory);
  });

  subMenu.addOption("Cleric", [&name, &inventory, &character]() {
    character = Character(name, CharacterClass::CLERIC, inventory);
  });

  subMenu.display();

  return character;
}

void displayStartupMenu(Character& character) {
  Menu startMenu("Main Menu");

  startMenu.addOption("New Game", [&character](){
    character = displayNewGameAndGetCharacter();
  });

  startMenu.addOption("Load Game", [](){ std::cout << "Loading a game from the save file is PLANNED..." << std::endl; });
  startMenu.addOption("Exit", [](){ std::cout << "Goodbye!" << std::endl; return 0; });

  startMenu.display();
}