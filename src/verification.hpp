#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>

/*
input verifications

- field empty
- choix definis à l'avance
- inferieur ou superieur à un range de nombre

*/

std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage);
char getValidInputChar(std::string const &nameField, std::string const &errorMessage, std::vector<char> const &validInputs);
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, int min, int max);
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, std::vector<int> const &validInputs);
int getValidPosition(std::string const &nameField, std::string const &errorMessage, std::array<char, 9> const &gameBoard, char empty = ' ');
