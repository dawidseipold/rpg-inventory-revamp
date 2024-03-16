#include "../../includes/container/container.h"

void Container::addItem(const Item& item) {
  if (currentWeight + item.getWeight() <= maxWeight) {
    currentWeight += item.getWeight();
    items.push_back(item);
  } else {
    std::cout << "The container is full!" << std::endl;
  }
}

void Container::removeItem(const Item& item) {
  auto itemToRemove = std::remove(items.begin(), items.end(), item);

  items.erase(itemToRemove, items.end());

  currentWeight -= item.getWeight();
};

void Container::setMaxWeight(int newMaxWeight) {
  Container::maxWeight = newMaxWeight;
};

[[maybe_unused]] [[nodiscard]] const std::vector<Item>& Container::getItems() const {
  return items;
};

[[maybe_unused]] [[nodiscard]] int Container::getCurrentWeight() const {
  return currentWeight;
};

[[maybe_unused]] [[nodiscard]] int Container::getMaxWeight() const {
  return maxWeight;
};

[[maybe_unused]] [[nodiscard]] std::string Container::getName() {
  return name;
}

void Container::displayItems() const {
  if (items.empty()) {
    std::cout << "No items found!" << std::endl;
  } else {
    for (const Item& item : items) {
      item.displayProperties();
    }
  }
};