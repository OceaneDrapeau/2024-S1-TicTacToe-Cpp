#include "verification.hpp"

std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage)
{
    // Initializations
    std::string input{};

    // Code
    do
    {
        std::cout << nameField;
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << errorMessage << std::endl;
        }

    } while (input.empty());

    return input;
};

char getValidInputChar(std::string const &nameField, std::string const &errorMessage, std::vector<char> const &validInputs)
{
    // Initializations
    char input{};
    char inputUpper{};
    bool inputValid{false};

    // Code
    do
    {
        std::cout << nameField;
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
        }
        else
        {
            inputUpper = std::toupper(input);
            for (char valid : validInputs)
            {
                if (inputUpper == std::toupper(valid))
                {
                    inputValid = true;
                    break;
                }
            }
        }

        if (!inputValid)
        {
            std::cout << errorMessage;
        }

    } while (!inputValid);

    return input;
};
