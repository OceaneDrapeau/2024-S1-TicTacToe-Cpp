#pragma once
#include <iostream>
#include <string>
#include "verification.hpp"

struct Player
{
    std::string name;
    char symbol;
};

Player create_player(char symbol1 = 'X', char symbol2 = 'O');
Player create_player(char symbolPlayer, char symbol1 = 'X', char symbol2 = 'O', bool AI = true);
