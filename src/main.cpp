#include <iostream>
#include "player.hpp"
#include "game_board.hpp"

int main()
{
    // Fix UTF-8 in the terminal
    std::setlocale(LC_ALL, ".65001");

    // Initializations
    Player user1{create_player()};
    std::array<int, 9> gameBoard{construct_game_board()};

    draw_game_board(gameBoard);

        return 0;
}