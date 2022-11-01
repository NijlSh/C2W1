#include "Algorithm.h"

void DestinationList(const dynamic_array flight) 
{
	while (true) 
	{
		std::string value = "";

		std::cout << "������� ����� ����������." << std::endl;
		std::cout << "����: ";

		std::getline(std::cin, value);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int count = 0;
		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDestination() == value)
			{
				std::cout << std::endl;
				flight.ptr[i].ShowFlight(count);
				count++;
			}
		}
		if (count == 0)
			std::cout << "����� � ����� ����� ���������� ����������." << std::endl;

		std::cout << "����� ����� � ���� �����?\n1 - ���\n2 - ��" << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		system("cls");
		if (end_program == endChoice::yes)
		{
			return;
		}
	}
}

void WeekdayAndTimeList(const dynamic_array flight) 
{
	while (true) 
	{
		std::cout << "�������� ���� ������." << std::endl;
		std::cout << "1 - �����������, 2 - �������, 3 - �����, 4 - �������, 5 - �������, 6 - �������, 7 - �����������." << std::endl;

		std::cout << "����: ";
		int number = CheckMenu(max_day);

		std::cout << "�������� �����  � ���������� �� 00:00 �� 23:59." << std::endl;
		std::cout << "������� ����." << std::endl;
		time_type temp_time = { 0, 0 };
		while (true)
		{
			std::cout << "����: ";
			temp_time.hour_ = GetPositiveInt();
			if (temp_time.hour_ > max_hour - 1)
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
			temp_time.minute_ = GetPositiveInt();
			if (temp_time.minute_ > max_minute - 1)
			{
				std::cout << "������� ����� �� ����� 60." << std::endl;
				continue;
			}
			break;
		}

		int count = 0;
		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDepartureDay() == week_day[number])
			{
				time_type temp = flight.ptr[i].GetDepartureTime();
				if (temp.hour_ >= temp_time.hour_ && temp.minute_ >= temp_time.minute_) 
				{
					std::cout << std::endl;
					flight.ptr[i].ShowFlight(count);
					count++;
				}
			}
		}
		if (count == 0)
			std::cout << "����� � ����� ����� ���������� ����������." << std::endl;

		std::cout << "����� ����� � ���� �����?\n1 - ���\n2 - ��" << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		system("cls");
		if (end_program == endChoice::yes)
		{
			return;
		}
	}
}

void WeekdayList(const dynamic_array flight) 
{
	while (true) 
	{
		std::cout << "���������� ���� ������." << std::endl;
		std::cout << "1 - �����������, 2 - �������, 3 - �����, 4 - �������, 5 - �������, 6 - �������, 7 - �����������." << std::endl;

		std::cout << "����: ";
		int number = CheckMenu(max_day);

		int count = 0;
		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDepartureDay() == week_day[number])
			{
				std::cout << std::endl;
				flight.ptr[i].ShowFlight(count);
				count++;
			}
		}
		if (count == 0)
			std::cout << "����� � ����� ����� ���������� ����������." << std::endl;

		std::cout << "����� ����� � ���� �����?\n1 - ���\n2 - ��" << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		system("cls");
		if (end_program == endChoice::yes)
		{
			return;
		}
	}
}
