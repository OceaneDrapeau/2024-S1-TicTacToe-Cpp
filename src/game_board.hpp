#pragma once

#include <iostream>
#include <array>

std::array<char, 9> construct_game_board(char const empty);
void draw_game_board(std::array<char, 9> gameBoard, char const empty);