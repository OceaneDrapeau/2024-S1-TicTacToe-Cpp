#include "player.hpp"

// Name of the player
std::string playerName()
{
    std::string nameField{"Nom : "};
    std::string errorMessage{"Le nom ne peut pas être vide. Réessayez."};
    std::string name{getValidInputStr(nameField, errorMessage)};

    return name;
}

// Symbol of the player
char playerSymbol(char symbol1, char symbol2)
{
    char symbol{};
    std::string firstSymbol{};
    std::string secondSymbol{};
    firstSymbol.push_back(symbol1);
    secondSymbol.push_back(symbol2);

    std::string nameField{"Symbole (" + firstSymbol + " ou " + secondSymbol + ") : "};
    std::string errorMessage{"Choisir un symbole valide. Réessayez."};
    std::vector<char> validInputs{'X', 'O'};
    char symbol{getValidInputChar(nameField, errorMessage, validInputs)};

    symbol = (std::toupper(symbol) == std::toupper(symbol1)) ? symbol1 : symbol2;

    return symbol;
}

Player create_player(char symbol1, char symbol2)
{
    // Initializations
    Player player{};
    char tempSymbol{};

    player.name = playerName();
    player.symbol = playerSymbol(symbol1, symbol2);

    return player;
};

Player create_player(Player player1, char symbol1, char symbol2, bool AI)
{
    Player player{};

    player.name = (AI) ? "AI" : playerName();

    char symbolPlayer1{player1.symbol};
    player.symbol = (symbolPlayer1 == symbol1) ? symbol2 : symbol1;

    return player;
}