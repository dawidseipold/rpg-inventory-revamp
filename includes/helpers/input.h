#ifndef RPG_INVENTORY_REVAMP_INPUT_H
#define RPG_INVENTORY_REVAMP_INPUT_H

#include <iostream>
#include <limits>

template <typename T> T getValidInput(const std::string &prompt, const std::string &errorMessage = "");
template <typename First, typename Second> std::pair<First, Second> getValidPairInput(const std::string &promptFirst, const std::string &promptSecond, const std::string &errorMessage = "");

#endif //RPG_INVENTORY_REVAMP_INPUT_H
