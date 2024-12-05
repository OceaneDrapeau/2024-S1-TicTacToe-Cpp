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
    Player player1{create_player()};
    Player player2{create_AI(player1.symbol)};

    draw_game_board(gameBoard);
    if (choiceStartMenu == 1)
    {
        // manque des vérifs (le j2 peut prendre même symbole pour l'instant)
        player2 = create_player();
    }

        return 0;
}