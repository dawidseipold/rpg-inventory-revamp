#include "../../includes/helpers/input.h"

template <typename T> T getValidInput(const std::string &prompt, const std::string &errorMessage) {
  T input;
  std::cout << prompt;

  while(!(std::cin >> input)) {
    if (!errorMessage.empty()) {
      std::cout << errorMessage;
    } else {
      std::cout << "Invalid input. Please try again." << std::endl;
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return input;
}

template int getValidInput<int>(const std::string &prompt, const std::string &errorMessage);
template float getValidInput<float>(const std::string &prompt, const std::string &errorMessage);
template double getValidInput<double>(const std::string &prompt, const std::string &errorMessage);
template std::string getValidInput<std::string>(const std::string &prompt, const std::string &errorMessage);