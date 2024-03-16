#include "../../../includes/container/chest/chest.h"

void Chest::displayProperties() const {
  std::cout << "Chest name: " << name << std::endl;
  std::cout << "Max weight: " << maxWeight << std::endl;
  std::cout << "Current weight: " << currentWeight << std::endl;
  std::cout << "Coordinates: (" << coordinates.first << ", " << coordinates.second << ")" << std::endl;
}

std::pair<int, int> Chest::getCoordinates() const {
  return coordinates;
}

void Chest::setName(const std::string &newName) {
  name = newName;
}
