#include "EnterData.h"

void EnterDepartureTime(Flight& object)
{
	time_type temp = { 0, 0 };

	std::cout << "Установите время вылета в промежутке от 00:00 до 23:59." << std::endl;
	std::cout << "Введите часы." << std::endl;
	while (true)
	{
		std::cout << "Ввод: ";
		temp.hour_ = GetPositiveInt();
		if (temp.hour_ > max_hour - 1)
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
		temp.minute_ = GetPositiveInt();
		if (temp.minute_ > max_minute - 1)
		{
			std::cout << "Введите число не более 60." << std::endl;
			continue;
		}
		break;
	}
	object.SetDepartureTime(temp);
}


void EnterDepartureDay(Flight& object)
{
	std::cout << "Установите день недели." << std::endl;
	std::cout << "1 - понедельник, 2 - вторник, 3 - среда, 4 - четверг, 5 - пятница, 6 - суббота, 7 - воскресенье." << std::endl;

	std::cout << "Ввод: ";
	int number = CheckMenu(max_day);

	object.SetDepartureDay(week_day[number]);
}


void EnterPlaneType(Flight& object)
{
	std::cout << "Установите тип самолёта." << std::endl;
	std::cout << "1 - Airbus A380, 2 - Boeing 787 Dreamliner, 3 - Туполев Ту-154." << std::endl;

	std::cout << "Ввод: ";
	
	int number = CheckMenu(max_plane);
	 object.SetPlaneType(plane_type[number]);
}



void EnterDestination(Flight& object)
{
	std::string temp = "";

	std::cout << "Установите пункт назначения." << std::endl;

	while(true)
	{
		std::cout << "Ввод: ";
		getline(std::cin, temp);
		for (const char c : temp) 
		{
			if (isdigit(c))
			{
				std::cout << "Название не должно содержать цифр. Повторите ввод." << std::endl;
				break;
			}
		}
		break;
	}
	object.SetDestination(temp);
}
