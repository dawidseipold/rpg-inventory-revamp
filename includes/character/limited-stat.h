#ifndef RPG_INVENTORY_REVAMP_LIMITED_STAT_H
#define RPG_INVENTORY_REVAMP_LIMITED_STAT_H

#include <iostream>

class LimitedStat {
  int value;
  int cap;

public:
  explicit LimitedStat(
    int value,
    int cap
  ) : value(value),
      cap(cap) {
    this->value = std::min(value, cap);
  }

  //  Setters
  void setValue(int newValue);
  void setCap(int newCap);

  //  Getters
  [[nodiscard]] int getValue() const;
  [[nodiscard]] int getCap() const;
};

#endif //RPG_INVENTORY_REVAMP_LIMITED_STAT_H
