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

	std::cout << "����������" << std::endl;
	std::cout << "�������" << std::endl;

	while (true)
	{
		dynamic_array flight = { 0, true, nullptr };
		std::cout << "����: 1 - ���������� ������, 2 - ���������� ����. 3 - �������� ����." << std::endl;
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
			std::cout << "�������." << std::endl;
			system("pause");
		}

		if (!flight.isCorrect) 
		{
			system("cls");
			continue;
		}


		std::cout << "�������� ������ ������ ������: 1 - ���������� �����, 2 - �������� �����." << std::endl;
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
			std::cout << "�������." << std::endl;
			system("pause");
		}

		while (true) 
		{
			std::cout << "������� ������: 1 - ������ �� ������ ����������, 2 - ������ �� ��� ������ � �������, 3 - ������ �� ��� ������." << std::endl;
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
				std::cout << "�������." << std::endl;
				system("pause");
			}
			std::cout << "����������� ���� ������: 1 - ���, 2 - ��." << std::endl;
			endChoice end_list_selection = static_cast<endChoice>(CheckMenu(two));
			if (end_list_selection == endChoice::no)
				break;
		}
		delete[] flight.ptr;
		std::cout << "��������� ���������: 1 - ���, 2 - ��." << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		if (end_program == endChoice::yes) 
			return 0;
		system("cls");
	}
}