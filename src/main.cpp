#include <iostream>
#include "player.hpp"
#include "game_board.hpp"
#include "game_play.hpp"
#include "menu.hpp"

int main()
{
    // Fix UTF-8 in the terminal
    std::setlocale(LC_ALL, ".65001");

    // Initializations

    // Change display
    bool help{};

    // Generic characters
    char empty = ' ';
    char const symbol1{'X'};
    char const symbol2{'O'};

    // Directions
    std::vector<Move> directions{
        Move::Up,
        Move::Down,
        Move::Left,
        Move::Right,
        Move::LeftToRightDown,
        Move::RightToLeftUp,
        Move::RightToLeftDown,
        Move::LeftToRightUp};

    // Game board
    std::array<char, 9> gameBoard{create_game_board(' ')};

    // Players
    Player player1{};
    Player player2{};

    // Game play
    bool gameOver{false};
    int turn{};
    int lastPosition{0};

    // Menu
    int choiceStartMenu{startMenu()};
    bool AI{choiceStartMenu == 2};

    // Create Players
    std::cout << "\nJoueur 1" << std::endl;
    player1 = create_player();

    std::cout << ((!AI) ? "\nJoueur 2" : "") << std::endl;

    player2 = create_player(player1, symbol1, symbol2, AI);
    std::cout << std::endl;

    // Rearrange player 1 to symbol 1
    if (player2.symbol == symbol1)
    {
        std::swap(player1, player2);
    }

    // The game
    draw_game_board(gameBoard, empty, help);
    do
    {
        std::cout << std::endl;
        lastPosition = play(gameBoard, player1, turn, player1.isAI, empty, help);
        gameOver =
            (lastPosition == -1)
                ? true
                : win(gameBoard, directions, lastPosition, turn, empty);

        std::swap(player1, player2);
        turn += 1;

        // Check if it's last turn
        if (turn >= static_cast<int>(gameBoard.size()))
        {
            std::cout << "\nC'est un match nul !" << std::endl;
            gameOver = true;
            lastPosition = -1;
        }

    } while (!gameOver);

    if (lastPosition != -1)
    {
        std::cout << std::endl;
        std::cout << player2.name << " a gagné !" << std::endl;
    }

    return 0;
}