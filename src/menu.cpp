#include "menu.hpp"
#include "player.hpp"

int start_menu()
{
    int choice{};

    std::cout << "Bienvenue dans le jeu du TicTacToe \nVeuillez choisir un mode de jeu :" << std::endl;

    std::cout << "1. Deux joueurs \n2. Un joueur contre l'IA" << std::endl;
    std::cin >> choice;

    return choice;
}
