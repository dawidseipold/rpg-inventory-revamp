#include <iostream>
#include <format>

#include "includes/weapon/melee/models/axe.h"

int main() {
    Axe axe("Axe", "Axe description", 100, 10, ItemRarity::COMMON, 10, 20, 10, 2, 80, Influence::NONE, 2, 2, 2, DamageType::SLASH);

    std::cout << std::format("Axe name: {}", axe.getName()) << std::endl;

    return 0;
}
