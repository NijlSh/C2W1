#include "FileInput.h"

dynamic_array FileInput()
{
	system("cls");
	std::ifstream file;
	std::string file_name;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	dynamic_array temp = { 0, true, nullptr };

	while (true)
	{
		try
		{
			file_name = GetFileName(input);
			file.open(file_name);
			std::cout << "���� ������� ������." << std::endl;
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "������ �������.\n" << "������ ����������� �����? 1 � ���, 2 � ��" << std::endl;
			std::cout << "����: ";
			int user_choice = CheckMenu(two);
			if (user_choice != restart)
				temp.isCorrect = false;
				return temp;
		}
	}

	Flight object;
	try
	{
		int size = getLineI(file);
		if (size > max_size || size <= 0)
			throw error;

		temp.size = size;
		temp.ptr = new Flight[size];
		for (int i = 0; i < size; i++)
		{
			std::string day = getLineS(file);
			bool isValid = false;
			for (int j = 0; j < max_day; j++)
			{
				if (day == week_day[j])
				{
					isValid = true;
					break;
				}
			}
			if (!isValid)
				throw error;

			int hour = getLineI(file);
			if (hour > max_hour - 1)
				throw error;

			int minute = getLineI(file);
			if (minute > max_minute - 1)
				throw error;
			time_type time_ = { hour, minute };

			std::string destination = getLineS(file);

			for (char c : destination)
			{
				if (SymbolCheck(c))
					throw error;
			}

			std::string plane = getLineS(file);
			isValid = false;
			for (int j = 0; j < max_plane; j++)
			{
				if (plane == plane_type[j])
				{
					isValid = true;
					break;
				}
			}
			if (!isValid)
				throw error;

			object.SetDepartureDay(day);
			object.SetDepartureTime(time_);
			object.SetPlaneType(plane);
			object.SetDestination(destination);
			temp.ptr[i] = object;
		}
		std::cout << "������ ������� �������." << std::endl;
		file.close();
		return temp;
	}

	catch (int)
	{
		std::cout << "������������ ������ ������." << std::endl;
		file.close();
		delete[] temp.ptr;
		temp = { 0, false, nullptr };
		system("pause");
		return temp;
	}
	catch (const std::exception&)
	{
		std::cout << "������ ��� ������ ���������� �� �����." << std::endl;
		file.close();
		temp.isCorrect = false;
		system("pause");
		return temp;
	}
}