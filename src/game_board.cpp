#include "game_board.hpp"

// Initialization of game board to all empty
std::array<char, 9> create_game_board(char const empty)
{
    std::array<char, 9> gameBoard{};
    gameBoard.fill(empty);
    return gameBoard;
}

// Display game board
void draw_game_board(std::array<char, 9> const &gameBoard, char const empty, bool const help)
{
    // Initializations
    int newLine{3};
    char const separator{'|'};
    int count{0};

    // Display
    for (char element : gameBoard)
    {
        std::cout << separator << empty;
        count += 1;
        if (help && element == empty)
        {
            std::cout << count << empty;
        }
        else
        {
            std::cout << element << empty;
        }

        newLine -= 1;

        if (newLine == 0)
        {
            std::cout << separator << std::endl;
            newLine = 3;
        }
    }
}