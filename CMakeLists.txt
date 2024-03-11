cmake_minimum_required(VERSION 3.27)
project(rpg_inventory_revamp)

set(CMAKE_CXX_STANDARD 23)

add_executable(rpg_inventory_revamp main.cpp
        includes/item.h
        includes/weapon/weapon.h
        includes/influence.h
        includes/weapon/melee/melee.h
        includes/weapon/ranged/ranged.h
        includes/weapon/melee/models/axe.h
        includes/weapon/melee/models/hammer.h
        includes/weapon/melee/models/scythe.h
        includes/weapon/melee/models/sword.h
        includes/weapon/ranged/models/blunderbuss.h
        includes/weapon/ranged/models/cannon.h
        includes/weapon/ranged/models/pistol.h)
