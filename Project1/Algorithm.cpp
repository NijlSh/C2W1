#include "Algorithm.h"

void DestinationList(const dynamic_array flight) 
{
	while (true) 
	{
		std::string value = "";

		std::cout << "Введите пункт назначения." << std::endl;
		std::cout << "Ввод: ";

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
			std::cout << "Рейсы в такой пункт назначения отсутсвуют." << std::endl;

		std::cout << "Найти рейсы в иной пункт?\n1 - Нет\n2 - Да" << std::endl;
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
		std::cout << "Выберете день недели." << std::endl;
		std::cout << "1 - понедельник, 2 - вторник, 3 - среда, 4 - четверг, 5 - пятница, 6 - суббота, 7 - воскресенье." << std::endl;

		std::cout << "Ввод: ";
		int number = CheckMenu(max_day);

		std::cout << "Выберете время  в промежутке от 00:00 до 23:59." << std::endl;
		std::cout << "Введите часы." << std::endl;
		time_type temp_time = { 0, 0 };
		while (true)
		{
			std::cout << "Ввод: ";
			temp_time.hour_ = GetPositiveInt();
			if (temp_time.hour_ > max_hour - 1)
			{
				std::cout << "Введите число не больше 23." << std::endl;
				continue;
			}
			break;
		}

		std::cout << "Введите минуты." << std::endl;
		while (true)
		{
			std::cout << "Ввод: ";
			temp_time.minute_ = GetPositiveInt();
			if (temp_time.minute_ > max_minute - 1)
			{
				std::cout << "Введите число не более 60." << std::endl;
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
			std::cout << "Рейсы в такой пункт назначения отсутсвуют." << std::endl;

		std::cout << "Найти рейсы в иное время?\n1 - Нет\n2 - Да" << std::endl;
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
		std::cout << "Установите день недели." << std::endl;
		std::cout << "1 - понедельник, 2 - вторник, 3 - среда, 4 - четверг, 5 - пятница, 6 - суббота, 7 - воскресенье." << std::endl;

		std::cout << "Ввод: ";
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
			std::cout << "Рейсы в такой пункт назначения отсутсвуют." << std::endl;

		std::cout << "Найти рейсы в иное время?\n1 - Нет\n2 - Да" << std::endl;
		endChoice end_program = static_cast<endChoice>(CheckMenu(two));
		system("cls");
		if (end_program == endChoice::yes)
		{
			return;
		}
	}
}
