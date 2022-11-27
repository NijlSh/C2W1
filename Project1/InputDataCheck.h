#pragma once
#include <iostream>
#include <fstream>
#include <string>

const int error = 1;

int getLineI(std::ifstream& file);
double getLineD(std::ifstream& file);
std::string getLineS(std::ifstream& file);
