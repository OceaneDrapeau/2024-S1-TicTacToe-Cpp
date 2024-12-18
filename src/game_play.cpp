#include "game_play.hpp"

// Check all direction for a win condition based on the last position

int checkDirection(std::array<char, 9> const &gameBoard, int const lastPosition, Move const direction, int repeat, char const empty)
{
    // Initializations

    // game board
    int gameBoardSize{static_cast<int>(gameBoard.size())};
    int nbOfColumns{3};

    // Player
    int index{lastPosition};
    int move = static_cast<int>(direction);

    // Symbol
    char symbol{gameBoard[lastPosition]};

    // Code
    // Avoid wrong placement
    if (symbol == empty)
    {
        return -1;
    };

    // Check if end of the gameBoard
    while ((index + move >= 0 && index + move < gameBoardSize) && // check if out of range

           !((move == static_cast<int>(Move::Left) && index % nbOfColumns == 0) ||                // check if out of line by the left
             (move == static_cast<int>(Move::Right) && index % nbOfColumns == nbOfColumns - 1) || // check if out of line by the right

             (move == static_cast<int>(Move::RightToLeftDown) && index % nbOfColumns == 0) ||            // check if out of diagonal by the left
             (move == static_cast<int>(Move::LeftToRightUp) && index % nbOfColumns == nbOfColumns - 1))) // check if out of diagonal by the right

    {
        index += move;

        // Same symbol
        if (symbol == gameBoard[index])
        {
            repeat += 1;
            if (repeat == 3)
            {
                return repeat;
            }
        }

        // Symbol different
        else
        {
            return 0;
        }
    }

    // End of the board but verification not complete
    return repeat;
}

// Directions
// Up = -3, Down = +3, Left = -1, Right = +1,
// Diagonal Left to Right Down (\) = +4, Diagonal Right to Left Up (\) = -4
// Diagonal Right to Left Down (/) = +2, Diagonal Left to Right Up (/) = -2

// Check if a player won
bool win(std::array<char, 9> const &gameBoard, std::vector<Move> const directions, int const lastPosition, int const turn, char const empty)
{
    if (turn < 2)
    {
        return false;
    };

    int change{0};
    bool skip{false};
    bool newDirection{true};

    int repeat{1};

    for (Move move : directions)
    {
        if (!skip)
        {
            repeat = checkDirection(gameBoard, lastPosition, move, repeat, empty);

            switch (repeat)
            {
            case -1:
                // empty placement
                return false;

            case 0:
                repeat = 1;
                skip = newDirection;
                break;

            case 3:
                return true;

            default:
                change += 1;
                if (change == 2)
                {
                    return false;
                }
                break;
            }
        }
        else
        {
            repeat = 1;
            skip = !skip;
        }

        newDirection = !newDirection;
    }

    return false;
}

int playAI(std::array<char, 9> &gameBoard, int turn, char const empty)
{
    int gameBoardSize{static_cast<int>(gameBoard.size())};
    if (turn > 7)
    {
        for (int i{0}; i < gameBoardSize; i++)
        {
            if (gameBoard[i] == empty)
            {
                return i;
            }
        }
    }
    return getRandomPosition(gameBoard, empty);
}
// Play one turn
int play(std::array<char, 9> &gameBoard, Player const player, int const turn, char const empty, bool const help)
{
    int position{-1};
    if (turn < static_cast<int>(gameBoard.size()))
    {
        // Initializations
        std::string symbol{};
        symbol.push_back(player.symbol);

        std::cout << "Tour de " << player.name << " (" << player.symbol << ")" << std::endl;

        position = (player.isAI)
                       ? playAI(gameBoard, turn, empty)
                       : getValidPosition("Emplacement : ", "Choisir un emplacement valide. Réessayez.", gameBoard);

        if (player.isAI)
        {
            std::cout << "Emplacement choisi par l'IA : " << position + 1 << std::endl;
        }

        gameBoard[position] = player.symbol;
        std::cout << std::endl;
        draw_game_board(gameBoard, empty, help);
    }

    return position;
}