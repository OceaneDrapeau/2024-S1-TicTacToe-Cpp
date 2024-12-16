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
char playerSymbol(char const symbol1, char const symbol2)
{
    std::string firstSymbol{};
    std::string secondSymbol{};
    firstSymbol.push_back(symbol1);
    secondSymbol.push_back(symbol2);

    std::string nameField{"Symbole (" + firstSymbol + " ou " + secondSymbol + ") : "};
    std::string errorMessage{"Choisir un symbole valide. Réessayez."};
    std::vector<char> validInputs{symbol1, symbol2};
    char symbol{getValidInputChar(nameField, errorMessage, validInputs)};

    symbol = (std::toupper(symbol) == std::toupper(symbol1)) ? symbol1 : symbol2;

    return symbol;
}

// Create first player (possible to call it without any parameters)
Player create_player(char const symbol1, char const symbol2)
{
    Player player{};
    player.name = playerName();
    player.symbol = playerSymbol(symbol1, symbol2);

    return player;
};

// Create second player
Player create_player(Player const &player1, char const symbol1, char const symbol2, bool const AI)
{
    return {
        (AI) ? "AI" : playerName(),
        (player1.symbol == symbol1) ? symbol2 : symbol1,
        AI};
}