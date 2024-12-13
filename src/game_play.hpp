#pragma once

#include <array>
#include <vector>
#include <terminal_ctrl.hpp>

#include "player.hpp"
#include "menu.hpp"

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

bool win(std::array<char, 9> const &gameBoard, std::vector<Move> directions, int lastPosition, char empty);
int play(std::array<char, 9> &gameBoard, Player player, int turn);