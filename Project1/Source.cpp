#include "Flight.h"
#include "GetFileName.h"
#include "Items.h"
#include "ConsoleInput.h"
#include "FileInput.h"
#include "ConsoleOutput.h"
#include "FileOutput.h"
#include "Algorithm.h"

#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);     
	SetConsoleOutputCP(1251);  
	setlocale(LC_CTYPE, "RU");    

	std::cout << "Вступление" << std::endl;
	std::cout << "Задание" << std::endl;

	while (true)
	{
		dynamic_array flight = { 0, true, nullptr };
		std::cout << "Меню: 1 - завершение работы, 2 - консольный ввод. 3 - файловый ввод." << std::endl;
		inputChoice input = static_cast<inputChoice>(CheckMenu(three));
		system("cls");
		switch (input)
		{
		case inputChoice::console_input:
			flight = ConsoleInput();
			break;
		case inputChoice::file_input:
			flight = FileInput();
			break;
		case inputChoice::quit:
			return 0;
		default:
			std::cout << "Костыль." << std::endl;
			system("pause");
		}

		if (!flight.isCorrect) 
		{
			system("cls");
			continue;
		}


		std::cout << "Выберете способ вывода данных: 1 - консольный вывод, 2 - файловый вывод." << std::endl;
		outputChoice output = static_cast<outputChoice>(CheckMenu(two));
		system("cls");
		switch (output)
		{
		case outputChoice::console_output:
			ConsoleOutput(flight);
			break;
		case outputChoice::file_output:
			if (!FileOutput(flight))
			{
				delete[] flight.ptr;
				system("pause");
				system("cls");
				continue;
			}
			break;
		default:
			std::cout << "Костыль." << std::endl;
			system("pause");
		}

		while (true) 
		{
			std::cout << "Вывести список: 1 - спосок по пункту назначения, 2 - список по дню недели и времени, 3 - список по дню недели." << std::endl;
			listChoice list = static_cast<listChoice>(CheckMenu(three));
			system("cls");
			switch (list)
			{
			case listChoice::destination_sort:
				DestinationList(flight);
				break;
			case listChoice::weekday_and_time_sort:
				WeekdayAndTimeList(flight);
				break;
			case listChoice::weekday_sort:
				WeekdayList(flight);
				break;
			default:
				std::cout << "Костыль." << std::endl;
				system("pause");
			}
			std::cout << "Рассмотреть иной список: 1 - нет, 2 - да." << std::endl;
			endChoice end_list_selection = static_cast<endChoice>(CheckMenu(two));
			if (end_list_selection == endChoice::no)
				break;
		}
		delete[] flight.ptr;
		std::cout << "Закончить программу: 1 - нет, 2 - да." << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		if (end_program == endChoice::yes) 
			return 0;
		system("cls");
	}
}