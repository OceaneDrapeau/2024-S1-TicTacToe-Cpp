#include <iostream>
#include "player.hpp"
#include "game_board.hpp"

int main()
{
    // Fix UTF-8 in the terminal
    std::setlocale(LC_ALL, ".65001");

    // Initializations
    Player user1{create_player()};
    return 0;
}