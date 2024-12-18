#pragma once

#include <array>
#include <vector>

#include "verification.hpp"
#include "player.hpp"
#include "menu.hpp"
#include "game_board.hpp"

// List of all the movements
enum class Move
{
    Up = -3,
    Down = 3,

    Left = -1,
    Right = 1,

    LeftToRightDown = 4,
    RightToLeftUp = -4,

    RightToLeftDown = 2,
    LeftToRightUp = -2
};

bool win(std::array<char, 9> const &gameBoard, std::vector<Move> const directions, int const lastPosition, int const turn, char const empty = ' ');
int play(std::array<char, 9> &gameBoard, Player const player, int const turn, char const empty = ' ', bool const help = false);