#ifndef RPG_INVENTORY_REVAMP_MENU_H
#define RPG_INVENTORY_REVAMP_MENU_H

#include <iostream>
#include <utility>
#include <vector>
#include <functional>

class Menu {
  std::string title;
  std::vector<std::pair<std::string, std::function<void()>>> options;

public :
  explicit Menu(std::string  title) : title(std::move(title)) {}

  void addOption(const std::string& option, const std::function<void()>& action);

  void Display();
};

#endif //RPG_INVENTORY_REVAMP_MENU_H
