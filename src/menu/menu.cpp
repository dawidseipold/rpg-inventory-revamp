#include <format>
#include "../../includes/menu/menu.h"

void Menu::addOption(const std::string &option, const std::function<void()>& action) {
  options.emplace_back(option, action);
}

void Menu::Display() {
  std::cout << title << std::endl;

  for (unsigned short i = 0; const auto& [option, _] : options) {
    std::cout << std::format("{}. {}", i + 1, option) << std::endl;
    i++;
  }

  int choice;
  std::cout << "Enter your choice: ";
  std::cin >> choice;

  if (choice > 0 && choice <= options.size() && options[choice - 1].second != nullptr) {
      options[choice - 1].second();
  } else {
    std::cout << "Invalid choice number." << std::endl;
    Display();
  }
}
