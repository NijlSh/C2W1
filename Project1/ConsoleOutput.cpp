#include "ConsoleOutput.h"

void ConsoleOutput(const dynamic_array temp) 
{
	for (int i = 0; i < temp.size; i++) 
	{
		temp.ptr[i].ShowFlight(i);
	}
}