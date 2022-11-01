#include "ConsoleInput.h"

dynamic_array ConsoleInput() 
{
	system("cls");
	while (true) 
	{

		dynamic_array array = { 0, true, nullptr };
		try 
		{
			std::cout << "Введите количество рейсов. Количество рейсов не должно быть больше двадцати." << std::endl; 
			while (true)
			{
				std::cout << "Ввод: ";
				array.size = GetPositiveInt();
				if (array.size > max_size)
				{
					std::cout << "Введено число больше двадцати. Повторите ввод.";
					continue;
				}
				array.ptr = new Flight [array.size];
				system("cls");
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка выделения памяти." << std::endl;
			delete[] array.ptr;
			continue;
		}
		try 
		{
			Flight temp;
			std::cout << "Установите рейсы." << std::endl;
			for (int i = 0; i < array.size; i++) 
			{
				EnterDepartureDay(temp);
				EnterDepartureTime(temp);
				EnterPlaneType(temp);
				EnterDestination(temp);
				array.ptr[i] = temp;
				std::cout << std::endl;
			}
			std::cout << "Список рейсов успешно заполнен." << std::endl;
			return array;
		}
		catch (const std::exception&)
		{
			std::cout << "Неопределённая ошибка." << std::endl;
			delete[] array.ptr;
			continue;
		}
	}
}