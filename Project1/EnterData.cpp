#include "EnterData.h"

void EnterDepartureTime(Flight& object)
{
	time_type temp = { 0, 0 };

	std::cout << "���������� ����� ������ � ���������� �� 00:00 �� 23:59." << std::endl;
	std::cout << "������� ����." << std::endl;
	while (true)
	{
		std::cout << "����: ";
		temp.hour_ = GetPositiveInt();
		if (temp.hour_ > max_hour - 1)
		{
			std::cout << "������� ����� �� ������ 23." << std::endl;
			continue;
		}
		break;
	}

	std::cout << "������� ������." << std::endl;
	while (true)
	{
		std::cout << "����: ";
		temp.minute_ = GetInt();
		if (temp.minute_ > max_minute - 1)
		{
			std::cout << "������� ����� �� ����� 60." << std::endl;
			continue;
		}
		break;
	}
	object.SetDepartureTime(temp);
}


void EnterDepartureDay(Flight& object)
{
	std::cout << "���������� ���� ������." << std::endl;
	std::cout << "1 - �����������, 2 - �������, 3 - �����, 4 - �������, 5 - �������, 6 - �������, 7 - �����������." << std::endl;

	int number = CheckMenu(max_day) - 1;

	object.SetDepartureDay(week_day[number]);
}


void EnterPlaneType(Flight& object)
{
	std::cout << "���������� ��� �������." << std::endl;
	std::cout << "1 - Airbus A380, 2 - Boeing 787 Dreamliner, 3 - ������� ��-154." << std::endl;
	
	int number = CheckMenu(max_plane) - 1;
	object.SetPlaneType(plane_type[number]);
}



void EnterDestination(Flight& object)
{
	std::string temp = "";
	std::cout << "���������� ����� ����������." << std::endl;

	while(true)
	{
		bool is_correct = true;
		std::cout << "����: ";
		getline(std::cin, temp);
		for (const char c : temp) 
		{
			is_correct = SymbolCheck(c);
			if (is_correct)
			{
				std::cout << "����� ���������� �� ������ ��������� ����." << std::endl;
				continue;
			}
		}
		break;
	}
	object.SetDestination(temp);
}
