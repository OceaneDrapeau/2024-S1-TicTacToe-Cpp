#include "game_play.hpp"

// Check all direction for a win condition based on the last position

std::array<int, 2> checkDirection(std::array<char, 9> const &gameBoard, int const lastPosition, Move const direction, int repeat, char const empty)
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
        return {false, -1};
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
                return {true, repeat};
            }
        }

        // Symbol different
        else
        {
            return {false, 0};
        }
    }

    // End of the board but verification not complete
    return {false, repeat};
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

    bool skip{false};
    bool newDirection{true};

    std::array<int, 2> result{false, 1};

    for (Move move : directions)
    {
        if (!skip)
        {
            result = checkDirection(gameBoard, lastPosition, move, result[1], empty);
            if (result[0])
            {
                return true;
            }
            else if (result[1] == 0 && newDirection)
            {
                skip = true;
            }
            else if (result[1] == -1)
            {
                // empty placement
                return false;
            }
        }
        else
        {
            result[1] = 1;
            skip = false;
        }
        newDirection = !newDirection;
    }

    return false;
}

// Find the next position empty for AI
int playAI(std::array<char, 9> &gameBoard, char const empty = ' ')
{
    for (int i{0}; i < static_cast<int>(gameBoard.size()); i++)
    {
        if (gameBoard[i] == empty)
        {
            return i;
        }
    }
    return -1;
}

// Play one turn
int play(std::array<char, 9> &gameBoard, Player const player, int const turn, bool const AI, char const empty, bool const help)
{
    if (turn < static_cast<int>(gameBoard.size()))
    {
        // Initializations
        std::string symbol{};
        symbol.push_back(player.symbol);

        std::cout << "Tour de " << player.name << " (" << player.symbol << ")" << std::endl;

        int position = (AI)
                           ? playAI(gameBoard, empty)
                           : getValidPosition("Emplacement : ", "Choisir un emplacement valide. Réessayez.\n", gameBoard);

        if (AI)
        {
            std::cout << "Emplacement choisi par l'IA : " << position + 1 << std::endl;
        }

        // If valid position change right symbol + display game board with changes
        if (position != -1)
        {
            gameBoard[position] = player.symbol;
            std::cout << std::endl;
            draw_game_board(gameBoard, empty, help);

            return position;
        }
    }

    return -1;
}