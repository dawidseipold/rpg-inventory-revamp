#include "includes/character/character.h"
#include "includes/utils/startup-menu.h"
#include "includes/utils/main-menu.h"
#include "includes/world/world.h"
#include "includes/helpers/input.h"


int main() {
  World world;
  Character character;

  displayStartupMenu(character);

  std::cout << "Welcome, " << character.getName() << "!" << std::endl;

  displayMainMenu(&character, &world);
}
