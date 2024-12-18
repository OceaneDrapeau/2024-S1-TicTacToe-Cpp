#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>

std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage);
char getValidInputChar(std::string const &nameField, std::string const &errorMessage, std::vector<char> const &validInputs);
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, int min, int max);
int getValidInputInt(std::string const &nameField, std::string const &errorMessage, std::vector<int> const &validInputs);
int getValidPosition(std::string const &nameField, std::string const &errorMessage, std::array<char, 9> const &gameBoard, char const empty = ' ');
int getRandomPosition(std::array<char, 9> &gameBoard, char const empty = ' ');