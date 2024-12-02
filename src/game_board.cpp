#include "game_board.hpp"

char const symbol1{'X'};
char const symbol2{'O'};
char const empty{' '};
char const separator{'|'};

std::array<int, 9> construct_game_board()
{
    std::array<int, 9> gameBoard{};
    gameBoard.fill(0);
    return gameBoard;
}

std::array<char, 9> int_to_char_game_board(std::array<int, 9> const gameBoard_int, char symbol1, char symbol2, char empty)
{
    int numberOfCells{9};
    std::array<char, 9> gameBoard_char{};

    for (int i{0}; i < numberOfCells; i++)
    {
        switch (gameBoard_int[i])
        {
        case 1:
            gameBoard_char[i] = symbol1;
            break;

        case 2:
            gameBoard_char[i] = symbol2;
            break;

        default:
            gameBoard_char[i] = empty;
            break;
        }
    }
    return gameBoard_char;
}

void draw_game_board(std::array<int, 9> gameBoard_int, char symbol1, char symbol2, char empty, char separator)
{
    std::array<char, 9> gameBoard{int_to_char_game_board(gameBoard_int, symbol1, symbol2, empty)};
    int newLine{3};
    // int count{0};

    for (char element : gameBoard)
    {
        // count += 1;
        // std::cout << separator << ' ' << count << ' ';

        std::cout << separator << ' ' << element << ' ';

        newLine -= 1;

        if (newLine == 0)
        {
            std::cout << separator << std::endl;
            newLine = 3;
        }
    }
}