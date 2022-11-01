#include "ConsoleInput.h"

dynamic_array ConsoleInput() 
{
	system("cls");
	while (true) 
	{

		dynamic_array array = { 0, true, nullptr };
		try 
		{
			std::cout << "������� ���������� ������. ���������� ������ �� ������ ���� ������ ��������." << std::endl; 
			while (true)
			{
				std::cout << "����: ";
				array.size = GetPositiveInt();
				if (array.size > max_size)
				{
					std::cout << "������� ����� ������ ��������. ��������� ����.";
					continue;
				}
				array.ptr = new Flight [array.size];
				system("cls");
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "������ ��������� ������." << std::endl;
			delete[] array.ptr;
			continue;
		}
		try 
		{
			Flight temp;
			std::cout << "���������� �����." << std::endl;
			for (int i = 0; i < array.size; i++) 
			{
				EnterDepartureDay(temp);
				EnterDepartureTime(temp);
				EnterPlaneType(temp);
				EnterDestination(temp);
				array.ptr[i] = temp;
				std::cout << std::endl;
			}
			std::cout << "������ ������ ������� ��������." << std::endl;
			return array;
		}
		catch (const std::exception&)
		{
			std::cout << "������������� ������." << std::endl;
			delete[] array.ptr;
			continue;
		}
	}
}