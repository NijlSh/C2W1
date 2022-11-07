#include "Flight.h"
#include "GetFileName.h"
#include "Items.h"
#include "ConsoleInput.h"
#include "FileInput.h"
#include "ConsoleOutput.h"
#include "FileOutput.h"
#include "Algorithm.h"
#include "Menu.h"

#include <iostream>
#include <string>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);     
	SetConsoleOutputCP(1251);  
	setlocale(LC_CTYPE, "RU");    

	std::cout << "Шарашидзе Н.Л. группа 415 контрольная работа 1 вариант 5" << std::endl;
	std::cout << "Необходимо разработать класс для указанной предметной области." << std::endl <<"Доступ к данным реализовать с помощью методов Set, Get, Show." 
		<< std::endl << "Рейс: пункт назначения, номер рейса, тип самолета, время вылета, дни недели." << std::endl <<"Создать массив объектов. Реализовать возможность получения :"
		<< std::endl << "– списка рейсов для заданного пункта назначения,"
		<< std::endl << "– списка рейсов для заданного дня недели,"
		<< std::endl << "– списка рейсов для заданного дня недели, время вылета для которых позже заданного." << std::endl;

	while (true)
	{
		dynamic_array flight = { 0, true, nullptr };
		inputChoice input_choice = InputMenu();
		system("cls");
		switch (input_choice)
		{
		case inputChoice::console_input:
			flight = ConsoleInput();
			break;
		case inputChoice::file_input:
			flight = FileInput();
			break;
		case inputChoice::quit:
			return 0;
		}

		if (!flight.isCorrect) 
		{
			system("cls");
			continue;
		}


		binaryChoice file_output_choice = OutputMenu();
		system("cls");
		if (file_output_choice == yes) 
		{
			if (!FileOutput(flight))
			{
				delete[] flight.ptr;
				system("pause");
				system("cls");
				continue;
			}
		}

		ConsoleOutput(flight);

		while (true) 
		{
			binaryChoice enter_list_choice = EnterListMenu();
			if (enter_list_choice == binaryChoice::no)
				break;
			listChoice list_choice = ListMenu();
			system("cls");
			switch (list_choice)
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
			}
		}
		delete[] flight.ptr;
		binaryChoice end_program_choice = EndProgramMenu();
		if (end_program_choice == binaryChoice::yes) 
			return 0;
		system("cls");
	}
}