#ifndef RPG_INVENTORY_REVAMP_MENU_H
#define RPG_INVENTORY_REVAMP_MENU_H

#include <iostream>
#include "../includes/character/character-class.h"
#include "character/character.h"

int displayStartupMenu();

bool displayMainMenu(Character& character);
std::string setCharacterName();
CharacterClass setCharacterClass();

#endif //RPG_INVENTORY_REVAMP_MENU_H
