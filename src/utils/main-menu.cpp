#include "../../includes/utils/main-menu.h"
#include "../../includes/helpers/input.h"
#include "../../includes/item/item-factory.h"
#include "../../lib/json.hpp"
//#include <nlohmann/json.hpp>

using json = nlohmann::json;

void setItemProperties(std::unique_ptr<Item>* item) {
  auto name = getValidInput<std::string>("Enter the name of the item: ");
  auto description = getValidInput<std::string>("Enter the description of the item: ");
  auto value = getValidInput<int>("Enter the value of the item: ");
  auto weight = getValidInput<int>("Enter the weight of the item: ");
  ItemRarity rarity = static_cast<ItemRarity>(getValidInput<int>("Enter the rarity of the item: "));

  (*item)->setName(name);
  (*item)->setDescription(description);
  (*item)->setValue(value);
  (*item)->setWeight(weight);
  (*item)->setRarity(rarity);
}

void displayItemCreationMenu(Chest& chest) {
  json itemsJson = {
    {"Weapon", {
      {"Melee", {
        "Axe",
        "Hammer",
        "Sword"
      }},
      {"Ranged", {
        "Blunderbuss",
        "Cannon",
        "Pistol"
      }}
    }}
  };

  Menu categoryMenu("Item Creation Menu");

  for (auto& [category, categoryItems]: itemsJson.items()) {
    categoryMenu.addOption(category, [&category, &chest, &categoryItems, &categoryMenu]() {
      Menu subCategoryMenu(std::format("{} Menu", category));

      for (auto& [subCategory, subCategoryItems]: categoryItems.items()) {
        subCategoryMenu.addOption(subCategory, [&subCategory, &subCategoryItems, &chest, &subCategoryMenu]() {
          Menu modelMenu(std::format("{} Menu", subCategory));

          for (const auto& model : subCategoryItems) {
            modelMenu.addOption(model, [&model, &chest, &modelMenu]() {
              std::unique_ptr<Item> item = ItemFactory::createItem(model);

              setItemProperties(&item);

              chest.addItem(*item);
              std::cout << "Item added to chest!" << std::endl;

              modelMenu.exit();
            });
          }

          subCategoryMenu.exit();

          while (!modelMenu.shouldExit) {
            modelMenu.display();
          }
        });
      }

      categoryMenu.exit();

      while (!subCategoryMenu.shouldExit) {
        subCategoryMenu.display();
      }
    });
  }

  while (!categoryMenu.shouldExit) {
    categoryMenu.display();
  }
}

Chest& getChestFromSelection(World* world) {
  Menu chestSelectionMenu("Chest Edit Menu");
  Chest* selectedChest = nullptr;

  if (world->getChests().empty()) {
    std::cout << "No chests found!" << std::endl;
    chestSelectionMenu.exit();
  } else {
    std:: cout << "Select a chest to edit" << std::endl;
  }

  for (std::unique_ptr<Chest>& chestPtr : world->getChests()) {
    Chest& chest = *chestPtr;

    chestSelectionMenu.addOption(chest.getName(), [&chest, &selectedChest, &chestSelectionMenu](){
      std::cout << std::format("Chest {}", chest.getName()) << std::endl;
      selectedChest = &chest;
      chestSelectionMenu.exit();
    });
  }

  while (!chestSelectionMenu.shouldExit) {
    chestSelectionMenu.display();
  }

  return *selectedChest;
}

void displayCharacterMenu(Character* character) {
  Menu characterMenu("Character Menu");

  characterMenu.addOption("View your character", [&character]() {
    character->displayCharacter();
  });

  characterMenu.addOption("Level up your character", [&character]() {
    character->useSkillPoints();
  });

  characterMenu.addOption("Add experience to your character", [&character]() {
    int experience = getValidInput<int>("Enter the amount of experience to add: ");

    character->addExperience(experience);
  });

  characterMenu.addOption("View your inventory", [&character]() {
    Inventory& inventory = character->getInventory();

    if (inventory.getItems().empty()) {
      std::cout << "No items found!" << std::endl;
      return;
    }

    std::cout << "Inventory: " << inventory.getName() << std::endl;
  });

  characterMenu.addOption("Go back", [&characterMenu]() {
    characterMenu.exit();
  });

  while (!characterMenu.shouldExit) {
    characterMenu.display();
  }
}

void displayWorldMenu(World* world) {
  Menu worldMenu("World Menu");

  worldMenu.addOption("Add chest", [&world](){
    auto name = getValidInput<std::string>("Enter the name of the chest: ");
    auto capacity = getValidInput<int>("Enter the capacity of the chest: ");
    auto coordinates = getValidPairInput<int, int>("Enter the X coordinate of the chest: ", "Enter the Y coordinate of the chest: ");

    world->addChest(std::make_unique<Chest>(name, capacity, std::pair<int, int>(coordinates.first, coordinates.second)));
  });

  worldMenu.addOption("Display chests", [&world](){
    Menu chestDisplayMenu("Chest Menu");

    if (world->getChests().empty()) {
      std::cout << "No chests found!" << std::endl;
      chestDisplayMenu.exit();
    }

    // TODO: Make the loop a reusable function
    chestDisplayMenu.addOption("Display all chests", [&world](){
      for (const std::unique_ptr<Chest>& chestPtr : world->getChests()) {
        Chest& chest = *chestPtr;

        chest.displayProperties();

        for (const Item& item : chest.getItems()) {
          item.displayProperties();
        }
      }
    });

    for (const std::unique_ptr<Chest>& chestPtr : world->getChests()) {
      Chest& chest = *chestPtr;

      chestDisplayMenu.addOption(chest.getName(), [&chest](){
          chest.displayProperties();

          for (const Item& item : chest.getItems()) {
            item.displayProperties();
          }
      });
    }

    chestDisplayMenu.addOption("Go back", [&chestDisplayMenu](){
      chestDisplayMenu.exit();
    });

    while (!chestDisplayMenu.shouldExit) {
      chestDisplayMenu.display();
    }
  });

  worldMenu.addOption("Edit chest", [&world](){
    Chest& selectedChest = getChestFromSelection(world);

    Menu chestEditMenu("Chest Edit Menu");

    chestEditMenu.addOption("Change chest name", [&selectedChest](){
      auto newName = getValidInput<std::string>("Enter the new name of the chest: ");

      selectedChest.setName(newName);
    });

    chestEditMenu.addOption("Change chest capacity", [&selectedChest](){
      auto newCapacity = getValidInput<int>("Enter the new capacity of the chest: ");

      selectedChest.setMaxWeight(newCapacity);
    });

    chestEditMenu.addOption("Add item to chest", [&selectedChest](){
      displayItemCreationMenu(selectedChest);

//      std::cout << "Item Creation is WORK IN PROGRESS..." << std::endl;
    });

    chestEditMenu.addOption("Remove item from chest", [](){
      std::cout << "Item Removal is PLANNED..." << std::endl;
    });

    chestEditMenu.addOption("Go back", [&chestEditMenu](){
      chestEditMenu.exit();
    });

    while (!chestEditMenu.shouldExit) {
      chestEditMenu.display();
    }
  });

  worldMenu.addOption("Remove container", [](){
    std::cout << "Container Menu!" << std::endl;
  });

  worldMenu.addOption("Go back", [&worldMenu](){
    worldMenu.exit();
  });

  while (!worldMenu.shouldExit) {
    worldMenu.display();
  }
}

void displayMainMenu(Character* character, World* world) {
  Menu mainMenu("Main Menu");

  mainMenu.addOption("Character Menu", [&character](){
    displayCharacterMenu(character);
  });

  mainMenu.addOption("World Menu", [&world](){
    displayWorldMenu(world);
  });

  mainMenu.addOption("Item Menu", [](){
    std::cout << "Item Menu and Item Actions are PLANNED..." << std::endl;
  });

  mainMenu.addOption("Exit", [&character](){
    std::cout << "Goodbye!" << std::endl;
    delete character;

    exit(0);
  });

  while (!mainMenu.shouldExit) {
    mainMenu.display();
  }
}