#include <iostream>
#include <string>
#pragma once

struct Player
{
    std::string name;
    char symbol;
};

Player create_player();
Player create_AI(char symbolPlayer, char symbol1 = 'X', char symbol2 = 'O');
