#include <iostream>
#include <format>
#include "includes/menu.h"
#include "includes/character/character-class.h"
#include "includes/character/character.h"


int main() {
  std::string name;
  CharacterClass characterClass;

  if (displayStartupMenu() == 2) {
    std::cout << "Goodbye!" << std::endl;
    return 0;
  }

  std::cout << "Welcome to the game!" << std::endl;
  name = setCharacterName();
  characterClass = setCharacterClass();

  Character character(name, characterClass);

  std::cout << "Character created!" << std::endl;

  character.displayCharacter();

  displayMainMenu(character);
  return 0;
}
