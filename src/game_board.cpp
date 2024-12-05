#include "game_board.hpp"

char const symbol1{'X'};
char const symbol2{'O'};
char const empty{' '};
char const separator{'|'};

std::array<char, 9> construct_game_board(char const empty)
{
    std::array<char, 9> gameBoard{};
    gameBoard.fill(empty);
    return gameBoard;
}

void draw_game_board(std::array<char, 9> const gameBoard, char const empty)
{
    int newLine{3};
    char const separator{'|'};
    // int count{0};

    for (char element : gameBoard)
    {
        // count += 1;
        // std::cout << separator << ' ' << count << ' ';

        std::cout << separator << empty << element << empty;

        newLine -= 1;

        if (newLine == 0)
        {
            std::cout << separator << std::endl;
            newLine = 3;
        }
    }
}