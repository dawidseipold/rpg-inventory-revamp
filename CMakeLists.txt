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
        src/item/weapon/stats-helpers.cpp)
