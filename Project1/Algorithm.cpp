#include "Algorithm.h"

void DestinationList(const dynamic_array flight) 
{
	while (true) 
	{
		std::string value = "";

		std::cout << "Введите пункт назначения." << std::endl;
		std::cout << "Ввод: ";

		std::getline(std::cin, value);
		dynamic_array list = { 0, true, nullptr };
		list = GetDestinationList(flight, value);
		if (list.size > 0) 
		{
			for (int i = 0; i < list.size; i++)
			{
				list.ptr[i].ShowFlight(i);
			}
		}
		else 
			std::cout << "Рейсы в данный пункт назначения отсутствуют." << std::endl;

		std::cout << "Найти рейсы в иной пункт?\n1 - нет\n2 - да" << std::endl;
		binaryChoice end_program = static_cast<binaryChoice>(CheckMenu(two));
		system("cls");
		if (end_program == binaryChoice::no)
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
		int number = CheckMenu(max_day) - 1;

		std::cout << "Выберете время  в промежутке от 00:00 до 23:59." << std::endl;
		std::cout << "Введите часы." << std::endl;
		time_type temp_time = { 0, 0 };
		while (true)
		{
			std::cout << "Ввод: ";
			temp_time.hour_ = GetNotNegativeInt();
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
			temp_time.minute_ = GetNotNegativeInt();
			if (temp_time.minute_ > max_minute - 1)
			{
				std::cout << "Введите число не более 60." << std::endl;
				continue;
			}
			break;
		}
		
		dynamic_array list = { 0, true, nullptr };
		list = GetWeekdayAndTimeList(flight, temp_time , number);
		if (list.size > 0)
		{
			for (int i = 0; i < list.size; i++)
			{
				list.ptr[i].ShowFlight(i);
			}
		}
		else
			std::cout << "Рейсы в данный день недели отсутсвуют." << std::endl;
		

		std::cout << "Найти рейсы в иное время?\n1 - Нет\n2 - Да" << std::endl;
		binaryChoice end_program = static_cast<binaryChoice>(CheckMenu(two));
		system("cls");
		if (end_program == binaryChoice::no)
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

		int number = CheckMenu(max_day) - 1;

		dynamic_array list = { 0, true, nullptr };
		list = GetWeekdayList(flight, number);
		if (list.size > 0)
		{
			for (int i = 0; i < list.size; i++)
			{
				list.ptr[i].ShowFlight(i);
			}
		}
		else
			std::cout << "Рейсы в данный день недели отсутсвуют." << std::endl;


		std::cout << "Найти рейсы в иное время?\n1 - Нет\n2 - Да" << std::endl;
		binaryChoice end_program = static_cast<binaryChoice>(CheckMenu(two));
		system("cls");
		if (end_program == binaryChoice::no)
			return;
	}
}


dynamic_array GetDestinationList(const dynamic_array flight, std::string value)
{
	int size = 0;
	for (int i = 0; i < flight.size; i++)
	{
		if (flight.ptr[i].GetDestination() == value)
		{
			size++;
		}
	}

	dynamic_array list = { size, true, nullptr };
	if (size > 0) 
	{
		list.ptr = new Flight[size];
		int j = 0;
		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDestination() == value)
			{
				list.ptr[j] = flight.ptr[i];
				j++;
			}
		}
	}
	return list;
}


dynamic_array GetWeekdayAndTimeList(const dynamic_array flight, time_type temp_time, int number)
{
	int size = 0;
	for (int i = 0; i < flight.size; i++)
	{
		if (flight.ptr[i].GetDepartureDay() == week_day[number])
		{
			time_type temp = flight.ptr[i].GetDepartureTime();
			if (temp.hour_ >= temp_time.hour_ && temp.minute_ >= temp_time.minute_)
			{
				size++;
			}
		}
	}

	dynamic_array list = { size, true, nullptr };
	if (size > 0) 
	{
		list.ptr = new Flight[size];
		int j = 0;
		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDepartureDay() == week_day[number])
			{
				time_type temp = flight.ptr[i].GetDepartureTime();
				if (temp.hour_ >= temp_time.hour_ && temp.minute_ >= temp_time.minute_)
				{
					list.ptr[j] = flight.ptr[i];
					j++;
				}
			}
		}
	}
	return list;
}


dynamic_array GetWeekdayList(const dynamic_array flight, int number)
{
	int size = 0;
	for (int i = 0; i < flight.size; i++)
	{
		if (flight.ptr[i].GetDepartureDay() == week_day[number])
		{
			size++;
		}
	}

	dynamic_array list = { size, true, nullptr };

	if (size > 0)
	{
		list.ptr = new Flight[size];
		int j = 0;

		for (int i = 0; i < flight.size; i++)
		{
			if (flight.ptr[i].GetDepartureDay() == week_day[number])
			{
				list.ptr[j] = flight.ptr[i];
				j++;
			}
		}
	}

	return list;
}