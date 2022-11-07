#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <filesystem>

#include "Check.h"

using namespace std::experimental::filesystem;

enum 
{ 
	output = 0,
	input = 1
};

const int restart = 2;

std::string GetFileName(int stream_type);

