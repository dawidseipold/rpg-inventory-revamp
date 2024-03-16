#include <format>
#include "../../includes/menu/menu.h"
#include "../../includes/helpers/input.h"

void Menu::addOption(const std::string &option, const std::function<void()>& action) {
  options.emplace_back(option, action);
}

void Menu::display() {
  std::cout << title << std::endl;

  for (unsigned short i = 0; const auto& [option, _] : options) {
    std::cout << std::format("{}. {}", i + 1, option) << std::endl;
    i++;
  }

  int choice = getValidInput<int>("Enter your choice: ");


  if (choice > 0 && choice <= options.size() && options[choice - 1].second != nullptr) {
      options[choice - 1].second();
  } else {
    displayError();
  }
}

void Menu::displayError(const std::string &message) {
  std::cout << message << std::endl;
}

void Menu::exit() {
  options.clear();
  shouldExit = true;
}
