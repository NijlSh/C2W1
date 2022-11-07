#pragma once

#include "Flight.h"

enum inputChoice
{
	quit = 1,
	console_input = 2,
	file_input = 3
};

enum binaryChoice 
{
	no = 1,
	yes = 2
};

enum listChoice
{
	destination_sort = 1,
	weekday_sort = 2,
	weekday_and_time_sort = 3
	
};

typedef struct
{
	int size;
	bool isCorrect;
	Flight* ptr;
} dynamic_array;

const int max_size = 20;