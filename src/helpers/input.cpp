#include "../../includes/helpers/input.h"

template<typename T>
void handleInvalidInput(const std::string& errorMessage) {
  if (!errorMessage.empty()) {
    std::cout << errorMessage;
  } else {
    std::cout << "Invalid input. Please try again." << std::endl;
  }

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T getValidInput(const std::string &prompt, const std::string &errorMessage) {
  T input;
  std::cout << prompt;

  while (!(std::cin >> input)) {
    handleInvalidInput<T>(errorMessage);
    std::cout << prompt;
  }

  return input;
}

template int getValidInput<int>(const std::string &prompt, const std::string &errorMessage);
template float getValidInput<float>(const std::string &prompt, const std::string &errorMessage);
template double getValidInput<double>(const std::string &prompt, const std::string &errorMessage);
template std::string getValidInput<std::string>(const std::string &prompt, const std::string &errorMessage);

template <typename First, typename Second>
std::pair<First, Second> getValidPairInput(const std::string &promptFirst, const std::string &promptSecond, const std::string &errorMessage) {
  First first;
  Second second;

  std::cout << promptFirst;
  while (!(std::cin >> first)) {
    handleInvalidInput<First>(errorMessage);
  }

  std::cout << promptSecond;
  while (!(std::cin >> second)) {
    handleInvalidInput<Second>(errorMessage);
  }

  return std::pair<First, Second>(first, second);
}

template std::pair<int, int> getValidPairInput<int, int>(const std::string &promptFirst, const std::string &promptSecond, const std::string &errorMessage);