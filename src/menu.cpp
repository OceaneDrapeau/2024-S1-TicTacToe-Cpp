#include "menu.hpp"
#include "player.hpp"

int start_menu()
{
    int choice{};

    std::cout << "Bienvenue dans le jeu du TicTacToe \nVeuillez choisir un mode de jeu :" << std::endl;

    std::cout << "1. Deux joueurs \n2. Un joueur contre l'IA" << std::endl;

    do
    {
        std::cout << "Mode : ";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2))
        {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cout << "Choisir un mode valide. Réessayez." << std::endl;
        }
    } while (choice != 1 && choice != 2);

    std::cin.ignore(255, '\n');

    return choice;
}
