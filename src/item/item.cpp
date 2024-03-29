#include "../../includes/item/item.h"

void Item::displayProperties() const {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Value: " << value << std::endl;
  std::cout << "Weight: " << weight << std::endl;
  std::cout << "Rarity: " << static_cast<bool>(itemRarityToString(rarity)) << std::endl;
}

ItemRarity Item::getRarity() const  {
  return rarity;
}

int Item::getWeight() const {
  return weight;
}

int Item::getValue() const {
  return value;
}

const std::string &Item::getDescription() const {
  return description;
}

const std::string &Item::getName() const {
  return name;
}

void Item::setName(const std::string &newName) {
  this->name = newName;
}

void Item::setDescription(const std::string &newDescription) {
  this->description = newDescription;
}

void Item::setValue(int newValue) {
  this->value = newValue;
}

void Item::setWeight(int newWeight) {
  this->weight = newWeight;
}

void Item::setRarity(ItemRarity newRarity) {
  this->rarity = newRarity;
}


