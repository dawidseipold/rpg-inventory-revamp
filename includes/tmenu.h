#ifndef RPG_INVENTORY_REVAMP_TMENU_H
#define RPG_INVENTORY_REVAMP_TMENU_H

#include <iostream>
#include "../includes/character/character-class.h"
#include "character/character.h"

int displayStartupMenu(Character pCharacter);
bool sdisplayMainMenu(Character& character);



void createNewGame();

std::string setCharacterName();
CharacterClass setCharacterClass();

#endif //RPG_INVENTORY_REVAMP_TMENU_H
