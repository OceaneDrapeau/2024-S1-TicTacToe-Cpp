#include "verification.hpp"

// cin.fail()
void invalidInput()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(255, '\n');
    };
};

// conditions for valid string input
bool validStr(std::string const &input)
{
    return !input.empty();
};

// conditions for valid char input based on a list of valid inputs
bool validChar(char input, std::vector<char> const &validInputs)
{
    input = std::toupper(input);
    for (char valid : validInputs)
    {
        if (input == std::toupper(valid))
        {
            return true;
        }
    }
    return false;
};

// conditions for valid int input based on a range
bool validInt(int input, int min, int max)
{
    return (input >= min && input <= max);
};

// conditions for valid input based on a list of valid inputs
bool validInt(int input, std::vector<int> const &validInputs)
{
    for (char valid : validInputs)
    {
        if (input == valid)
        {
            return true;
        }
    }
    return false;
};

// conditions for valid input position
bool validPosition(int input, std::array<char, 9> const &gameBoard, char const empty)
{
    if (input < 0 || input >= static_cast<int>(gameBoard.size()))
    {
        return false;
    }
    return gameBoard[input] == empty;
};

// Get a valid string input
std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage)
{
    // Initializations
    std::string input{};
    bool inputValid{false};
    bool start{true};

    // Code
    do
    {
        std::cout << nameField;

        if (start)
        {
            std::cin.ignore(255, '\n');
            start = false;
        }

        std::getline(std::cin, input);

        inputValid = validStr(input);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input;
};

// Get a valid input character
char getValidInputChar(std::string const &nameField, std::string const &errorMessage, std::vector<char> const &validInputs)
{
    // Initializations
    char input{};
    bool inputValid{false};

    // Code
    do
    {
        std::cout << nameField;
        std::cin >> input;

        invalidInput();
        inputValid = validChar(input, validInputs);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input;
};

// Get a valid input int based on a range
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, int min, int max)
{
    // Initializations
    int input{};
    bool inputValid{};

    // Code
    do
    {
        std::cout << nameField;
        std::cin >> input;

        invalidInput();
        inputValid = validInt(input, min, max);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input;
}

// Get a valid input int based on a list
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, std::vector<int> const &validInputs)
{
    // Initializations
    char input{};
    bool inputValid{false};

    // Code
    do
    {
        std::cout << nameField;
        std::cin >> input;

        invalidInput();
        inputValid = validInt(input, validInputs);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input;
}

// Get valid input position
int getValidPosition(std::string const &nameField, std::string const &errorMessage, std::array<char, 9> const &gameBoard, char const empty)
{
    // Initializations
    int input{};
    bool inputValid{false};

    // Code
    do
    {
        std::cout << nameField;
        std::cin >> input;

        invalidInput();
        inputValid = validPosition(input - 1, gameBoard, empty);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input - 1;
};

// Find a random empty position for AI
int getRandomPosition(std::array<char, 9> &gameBoard, char const empty)
{
    int randomInt{};
    int gameBoardSize{static_cast<int>(gameBoard.size())};

    do
    {
        randomInt = std::rand() % gameBoardSize;

    } while (gameBoard[randomInt] != empty);

    return randomInt;
}