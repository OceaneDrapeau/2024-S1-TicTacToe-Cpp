#pragma once

#include <iostream>
#include "menu.hpp"
#include "player.hpp"
#include "verification.hpp"

int startMenu();
int playMenu(std::array<char, 9> &gameBoard, Player player);