#include "EnterData.h"

void EnterDepartureTime(Flight& object)
{
	time_type temp = { 0, 0 };

	std::cout << "”становите врем€ вылета в промежутке от 00:00 до 23:59." << std::endl;
	std::cout << "¬ведите часы." << std::endl;
	while (true)
	{
		std::cout << "¬вод: ";
		temp.hour_ = GetPositiveInt();
		if (temp.hour_ > max_hour - 1)
		{
			std::cout << "¬ведите число не больше 23." << std::endl;
			continue;
		}
		break;
	}

	std::cout << "¬ведите минуты." << std::endl;
	while (true)
	{
		std::cout << "¬вод: ";
		temp.minute_ = GetInt();
		if (temp.minute_ > max_minute - 1)
		{
			std::cout << "¬ведите число не более 60." << std::endl;
			continue;
		}
		break;
	}
	object.SetDepartureTime(temp);
}


void EnterDepartureDay(Flight& object)
{
	std::cout << "”становите день недели." << std::endl;
	std::cout << "1 - понедельник, 2 - вторник, 3 - среда, 4 - четверг, 5 - п€тница, 6 - суббота, 7 - воскресенье." << std::endl;

	int number = CheckMenu(max_day) - 1;

	object.SetDepartureDay(week_day[number]);
}


void EnterPlaneType(Flight& object)
{
	std::cout << "”становите тип самолЄта." << std::endl;
	std::cout << "1 - Airbus A380, 2 - Boeing 787 Dreamliner, 3 - “уполев “у-154." << std::endl;
	
	int number = CheckMenu(max_plane) - 1;
	object.SetPlaneType(plane_type[number]);
}



void EnterDestination(Flight& object)
{
	std::string temp = "";
	std::cout << "”становите пункт назначени€." << std::endl;

	while(true)
	{
		bool is_correct = true;
		std::cout << "¬вод: ";
		getline(std::cin, temp);
		for (const char c : temp) 
		{
			is_correct = SymbolCheck(c);
			if (is_correct)
			{
				std::cout << "ѕункт назначени€ не должен содержать цифр." << std::endl;
				continue;
			}
		}
		break;
	}
	object.SetDestination(temp);
}
