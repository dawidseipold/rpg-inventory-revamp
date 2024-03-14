#include "../includes/tmenu.h"
#include "../includes/container/chest/chest.h"
#include "../includes/menu/menu.h"

#include <format>

int createAnEmptyContainer() {
  std::string name;
  int maxWeight;
  int containerChoice;
  std::string confirm;
  std::pair <int, int> coordinates;

  std::cout << "Enter a name for the container: ";
  std::getline(std::cin, name);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter the maximum weight for the container: ";
  std::cin >> maxWeight;

  std::cout << "Pick a type of container: " << std::endl;
  std::cout << "1. Inventory" << std::endl;
  std::cout << "2. Chest" << std::endl;

  std::cin >> containerChoice;

  do {
    switch (containerChoice) {
      case 1:
        std::cout << "Creating an inventory..." << std::endl;

        std::cout << "Are you sure you want to create an inventory? (Y/N)" << std::endl;
        std::cin >> confirm;

        if (confirm == "Y" || confirm == "y") {
          Inventory inventory(name, maxWeight);
        } else {
          std::cout << "Inventory creation cancelled." << std::endl;
        }

        return 0;

      case 2:
        std::cout << "Creating a chest..." << std::endl;

        std::cout << "Enter the x coordinate: ";
        std::cin >> coordinates.first;

        std::cout << "Enter the y coordinate: ";
        std::cin >> coordinates.second;

        std::cout << "Are you sure you want to create a chest? (Y/N)" << std::endl;
        std::cin >> confirm;

        if (confirm == "Y" || confirm == "y") {
          Chest chest(name, maxWeight, coordinates);
        } else {
          std::cout << "Chest creation cancelled." << std::endl;
        }

        return 0;

      case 0: {
        std::cout << "Goodbye!" << std::endl;
        return 0;
      }

      default:
        std::cout << "Invalid containerChoice. Please try again." << std::endl;
    }
  } while (true);


}

int displayContainerMenu() {
  int choice;
  std::cout << "1. Create an empty container" << std::endl; // Done
  std::cout << "2. Read a single container" << std::endl;
  std::cout << "3. Update a container" << std::endl;
  std::cout << "4. Delete a container" << std::endl;
  std::cout << "0. Quit" << std::endl;
  std::cin >> choice;

  do {
    switch (choice) {
      case 1: {
        std::cout << "Creating an empty container..." << std::endl;

        createAnEmptyContainer();
        break;
      }

      case 2:
        std::cout << "Reading a single container..." << std::endl;
        break;

      case 3:
        std::cout << "Updating a container..." << std::endl;
        break;

      case 4:
        std::cout << "Deleting a container..." << std::endl;
        break;

      case 0:
        return 0;

      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (true);
}

int sdisplayStartupMenu(Character *pCharacter) {
  int choice;

  std::cout << "Welcome to the RPG Inventory Revamp!" << std::endl;
  std::cout << "1. New Game" << std::endl;
  std::cout << "2. Load Game" << std::endl;
  std::cout << "0. Quit" << std::endl;

  std::cin >> choice;

  do {
    switch (choice) {
      case 1:
        std::cout << "Starting a new game..." << std::endl;

        return 1;
      case 2:
        std::cout << "Loading a game..." << std::endl;

        return 2;
      case 0:
        std::cout << "Goodbye!" << std::endl;

        return 0;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
  } while (true);
}

bool displayMainMenu(Character& character) {
  int choice;

  do {
    std::cout << "1. View your inventory" << std::endl; // Done
    std::cout << "2. View your character" << std::endl; // Done
    //  TODO: Create a container submenu
    std::cout << "3. Open a container menu" << std::endl;

    //  TODO: Create an item submenu
    std::cout << "7. Create an item" << std::endl;
    std::cout << "8. Read an item" << std::endl;
    std::cout << "9. Update an item" << std::endl;
    std::cout << "10. Delete an item" << std::endl;
    std::cout << "11. Transfer an item" << std::endl;

    std::cout << "0. Quit" << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << std::format("Displaying {0}'s inventory", character.getName()) << std::endl;

        for (const auto& item : character.getInventory().getItems()) {
          std::cout << item.getName() << std::endl;
        }

        break;

      case 2:
        character.displayCharacter();
        break;

      case 3: {
        std::cout << "Opening the container menu..." << std::endl;

        if (displayContainerMenu() == 0) {
          break;
        }
      }

      case 4:
        std::cout << "Create an item" << std::endl;
        break;

      case 5:
        std::cout << "Transfer item" << std::endl;

        break;

      case 0:
        std::cout << "Goodbye!" << std::endl;
        return false;

      default:
        std::cout << "Invalid containerChoice. Please try again." << std::endl;
    }
  } while (true);
}

void createNewGame() {
  std::string name;
  CharacterClass characterClass;

  std::cout << "Welcome to the game!" << std::endl;
  name = setCharacterName();
  characterClass = setCharacterClass();

  Character character(name, characterClass);

  std::cout << "Character created!" << std::endl;

  character.displayCharacter();

  displayMainMenu(character);
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

  do {
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
    }
  } while (true);
};