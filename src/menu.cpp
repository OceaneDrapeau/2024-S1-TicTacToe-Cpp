#include "menu.hpp"

// Display menu
int startMenu()
{
    std::cout << "\nBienvenue dans le jeu du TicTacToe\n"
              << std::endl;
    std::cout << "Veuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs \n2. Un joueur contre l'IA" << std::endl;

    return getValidInputInt("Mode : ", "Choisir un mode valide. Réessayez.", 1, 3);
}