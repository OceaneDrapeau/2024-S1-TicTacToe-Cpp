#include "menu.hpp"

int startMenu()
{
    std::cout << "Bienvenue dans le jeu du TicTacToe" << std::endl;
    std::cout << "\nVeuillez choisir un mode de jeu :" << std::endl;
    std::cout << "1. Deux joueurs \n2. Un joueur contre l'IA" << std::endl;

    return getValidInputInt("Mode : ", "Choisir un mode valide. Réessayez.\n", 1, 3);
}

int playMenu(std::array<char, 9> &gameBoard, Player player)
{
    std::string symbol{};
    symbol.push_back(player.symbol);

    std::cout << "Tour de " << player.name << "(" << player.symbol << ")" << std::endl;
    return getValidPosition("Emplacement : ", "Choisir un emplacement valide. Réessayez.\n", gameBoard);
}