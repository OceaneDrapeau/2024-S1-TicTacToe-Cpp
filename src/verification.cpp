#include "verification.hpp"

void invalidInput()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(255, '\n');
    };
};

bool validStr(std::string input)
{
    return input.empty();
};

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

bool validInt(int input, int min, int max)
{
    return (input >= min && input <= max);
};

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

bool validPosition(int input, std::array<char, 9> const &gameBoard, char empty)
{
    if (input < 0 || input >= static_cast<int>(gameBoard.size()))
    {
        return false;
    }
    return gameBoard[input] == empty;
};

std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage)
{
    // Initializations
    std::string input{};
    bool inputValid{false};

    // Code
    do
    {
        std::cout << nameField;
        std::getline(std::cin, input);
        inputValid = validStr(input);

        if (!inputValid)
        {
            std::cout << errorMessage << std::endl;
        }

    } while (!inputValid);

    return input;
};

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
            std::cout << errorMessage;
        }

    } while (!inputValid);

    return input;
};

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
            std::cout << errorMessage;
        }

    } while (!inputValid);

    return input;
}

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
            std::cout << errorMessage;
        }

    } while (!inputValid);

    return input;
}

int getValidPosition(std::string const &nameField, std::string const &errorMessage, std::array<char, 9> const &gameBoard, char empty)
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
        inputValid = validPosition(input, gameBoard, empty);

        if (!inputValid)
        {
            std::cout << errorMessage;
        }

    } while (!inputValid);

    return input;
};