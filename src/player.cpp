#include "player.hpp"

Player create_player()
{
    // Initializations
    Player player{};
    std::string tempSymbol{};
    std::string const symbol1{"X"};
    std::string const symbol2{"O"};

    // Name of the player
    do
    {
        std::cout << "Nom : ";
        std::getline(std::cin, player.name);

        if (player.name.empty())
        {
            std::cout << "Le nom ne peut pas être vide. Réessayez." << std::endl;
        }
    } while (player.name.empty());

    // Symbol of the player
    do
    {
        std::cout
            << "Symbole ('" << symbol1 << "' ou '" << symbol2 << "') : ";

        std::getline(std::cin, tempSymbol);

        //
        if (tempSymbol.size() == 1)
        {
            tempSymbol[0] = std::toupper(tempSymbol[0]);
        }

        if (tempSymbol != symbol1 && tempSymbol != symbol2)
        {
            std::cout << "Saisir un symbole valide." << std::endl;
        }
        else
        {
            player.symbol = (tempSymbol == symbol1) ? 1 : 2;
        };

    } while (tempSymbol != symbol1 && tempSymbol != symbol2);

    return player;
};