#pragma once
#include <string>
#include <iostream>
#include <vector>

/*
input verifications

- field empty
- choix definis à l'avance
- inferieur ou superieur à un range de nombre

*/

std::string getValidInputStr(std::string const &nameField, std::string const &errorMessage);
char getValidInputChar(std::string const &nameField, std::string const &errorMessage, std::vector<char> const &validInputs);
