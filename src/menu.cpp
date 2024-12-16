#include "menu.hpp"

// Display menu
int startMenu()
{
    std::cout << "\nBienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "\nVeuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs \n2. Un joueur contre l'IA" << std::endl;

    return getValidInputInt("Mode : ", "Choisir un mode valide. Réessayez.\n", 1, 3);
}