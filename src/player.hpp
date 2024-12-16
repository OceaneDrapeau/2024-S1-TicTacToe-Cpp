#pragma once
#include <iostream>
#include <string>
#include "verification.hpp"

struct Player
{
    std::string name;
    char symbol;
    bool isAI{false}; // more secure than name = "AI"
};

Player create_player(char const symbol1 = 'X', char const symbol2 = 'O');
Player create_player(Player const &player1, char const symbol1 = 'X', char const symbol2 = 'O', bool const AI = true);