#include "includes/character/character.h"
#include "includes/utils/startup-menu.h"


int main() {
  auto* character = new Character();

  displayStartupMenu(character);

  character->displayCharacter();

}
