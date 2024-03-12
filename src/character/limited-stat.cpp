#include "../../includes/character/limited-stat.h"

void LimitedStat::setValue(int newValue) {
  if (newValue > cap) {
    value = cap;
  } else {
    value = newValue;
  }
};

void LimitedStat::setCap(int newCap) {
  if (value > newCap) {
    value = newCap;
  }

  cap = newCap;
}

[[nodiscard]] int LimitedStat::getValue() const {
  return value;
}

[[nodiscard]] int LimitedStat::getCap() const {
  return cap;
}