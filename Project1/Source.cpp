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

	std::cout << "Шаарашидзе Н.Л. группа 415 контрольная работа 1 вариант 5" << std::endl;
	std::cout << "Необходимо разработать класс для указанной предметной области." << std::endl <<"Доступ к данным реализовать с помощью методов Set, Get, Show." 
		<< std::endl << "Рейс: пункт назначения, номер рейса, тип самолета, время вылета, дни недели." << std::endl <<"Создать массив объектов. Реализовать возможность получения :"
		<< std::endl << "– списка рейсов для заданного пункта назначения,"
		<< std::endl << "– списка рейсов для заданного дня недели,"
		<< std::endl << "– списка рейсов для заданного дня недели, время вылета для которых позже заданного." << std::endl;

	while (true)
	{
		dynamic_array flight = { 0, true, nullptr };
		std::cout << "Меню:" << std::endl << "1 - завершение работы" << std::endl << "2 - консольный ввод" << std::endl << "3 - файловый ввод" << std::endl;
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
		}

		if (!flight.isCorrect) 
		{
			system("cls");
			continue;
		}


		std::cout << "Выберете способ вывода данных" <<std::endl << "1 - консольный вывод" << std::endl << "2 - файловый вывод." << std::endl;
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
		}

		while (true) 
		{
			std::cout << "Вывести список:" << std::endl << "1 - список по пункту назначения" << std::endl << "2 - список по дню недели и времени" << std::endl << "3 - список по дню недели." << std::endl;
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
			}
			std::cout << "Рассмотреть иной список" << std::endl << "1 - нет" << std::endl << "2 - да." << std::endl;
			endChoice end_list_selection = static_cast<endChoice>(CheckMenu(two));
			if (end_list_selection == endChoice::no)
				break;
		}
		delete[] flight.ptr;
		std::cout << "Закончить программу" << std::endl << "1 - нет" << std::endl << "2 - да." << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		if (end_program == endChoice::yes) 
			return 0;
		system("cls");
	}
}