#pragma once
#include <iostream>
#include <string>

const int error_ = 1;

enum numberOfChoice 
{
	two = 2,
	three = 3
};

int CheckMenu(int items);
int GetPositiveInt();
bool isNumber(const std::string& str);