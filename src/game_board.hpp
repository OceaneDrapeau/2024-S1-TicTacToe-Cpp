#pragma once

#include <iostream>
#include <array>

std::array<int, 9> construct_game_board();
std::array<char, 9> int_to_char_game_board(std::array<int, 9> const gameBoard_int, char symbol1, char symbol2, char empty);
void draw_game_board(std::array<int, 9> gameBoard_int, char symbol1 = 'X', char symbol2 = 'O', char empty = ' ', char separator = '|');