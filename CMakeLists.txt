cmake_minimum_required(VERSION 3.27)
project(rpg_inventory_revamp)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpg_inventory_revamp main.cpp
        includes/item/item.h
        includes/item/weapon/weapon.h
        includes/item/influence.h
        includes/item/weapon/melee/melee.h
        includes/item/weapon/ranged/ranged.h
        includes/item/weapon/melee/models/axe.h
        includes/item/weapon/melee/models/hammer.h
        includes/item/weapon/melee/models/scythe.h
        includes/item/weapon/melee/models/sword.h
        includes/item/weapon/ranged/models/blunderbuss.h
        includes/item/weapon/ranged/models/cannon.h
        includes/item/weapon/ranged/models/pistol.h
        includes/item/weapon/stats-helpers.h
        includes/item/rarity.h
        src/item/weapon/stats-helpers.cpp
        src/item/weapon/melee/melee.cpp
        src/item/weapon/weapon.cpp
        src/item/weapon/ranged/ranged.cpp
        src/menu.cpp
        includes/menu.h
        includes/character/character.h
        includes/character/limited-stat.h
        includes/character/character-class.h
        src/character/character.cpp
        src/character/limited-stat.cpp
        includes/container/container.h
        includes/container/inventory/inventory.h
        src/character/character-class.cpp
        includes/container/chest/chest.h
)
