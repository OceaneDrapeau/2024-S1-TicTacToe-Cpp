#include <iostream>
#include "game_play.hpp"

std::array<int, 2> checkDirection(std::array<char, 9> const &gameBoard, int lastPosition, Move direction, int repeat, char empty)
{
    // Initializations
    // gameBoard
    int gameBoardSize{static_cast<int>(gameBoard.size())};
    int nbOfColumns{3};

    // Player
    int index{lastPosition};
    int move = static_cast<int>(direction);
    char symbol{gameBoard[lastPosition]};

    // Output
    std::array<int, 2> result{false, repeat};

    // Code
    // Alignement of 3 empty
    if (symbol == empty)
    {
        result[1] = 1;
        return result;
    };

    // Check if end of the gameBoard
    while ((index + move >= 0 && index + move < gameBoardSize) && // check if out of range

           !((move == static_cast<int>(Move::Left) && index % nbOfColumns == 0) ||                // check if out of line by the left
             (move == static_cast<int>(Move::Right) && index % nbOfColumns == nbOfColumns - 1) || // check if out of line by the right

             (move == static_cast<int>(Move::RightToLeftDown) && index % nbOfColumns == 0) || // check if out of diagonal by the left
             (move == static_cast<int>(Move::LeftToRightUp) && index % nbOfColumns == 2)))    // check if out of diagonal by the right

    {
        index += move;

        // Same symbol
        if (symbol == gameBoard[index])
        {
            repeat += 1;
            if (repeat == 3)
            {
                result[0] = true;
                return result;
            }
        }

        // Symbol different
        else
        {
            result[1] = 1;
            return result;
        }
    }

    // End of the board but verification not complete
    result[1] = repeat;
    return result;
}

// Directions
// Up = -3, Down = +3, Left = -1, Right = +1,
// Diagonal Left to Right Down (\) = +4, Diagonal Right to Left Up (\) = -4
// Diagonal Right to Left Down (/) = +2, Diagonal Left to Right Up (/) = -2

bool win(std::array<char, 9> const &gameBoard, std::vector<Move> directions, int lastPosition, char empty)
{
    std::array<int, 2> result{false, 1};

    for (Move move : directions)
    {
        result = checkDirection(gameBoard, lastPosition, move, result[1], empty);
        if (result[0])
        {
            return true;
        }
    }
    return false;
}

