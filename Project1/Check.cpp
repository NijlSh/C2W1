#include "Check.h"

int CheckMenu(int items)
{
	std::cout << "����: ";
	while (true)
	{
		int value = 0;
		try
		{
			value = GetPositiveInt();
			if (value <= items && value >= 1)
				return value;
			else
				throw value;
		}
		catch (int ex_value)
		{
			std::cout << std::endl;
			std::cout << ex_value << " � �� ������������ ����� ����. ��������� ����: ";
			continue;
		}
	}
}

template<typename T>
T GetValue() 
{
	T temp = static_cast<T>(0.0);
	do
	{
		try
		{
			std::cin >> temp;
			std::cout << std::endl;
			if (std::cin.peek() != '\n')
				throw std::exception("IncorrectValue");
			return temp;
		}
		catch (const std::exception&)
		{
			std::cout << "������� ������������ ������. ��������� ����: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}

template <typename T>
T GetPositiveValue()
{
	T temp = static_cast<T>(0.0);
	do
	{
		try
		{
			temp = GetValue<T>();
			if (temp <= 0) throw error_;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return temp;
		}
		catch (const int&)
		{
			std::cout << "����� ������ ���� �������������. ��������� ����: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}

template <typename T>
T GetNotNegativeValue()
{
	T temp = static_cast<T>(0.0);
	do
	{
		try
		{
			temp = GetValue<T>();
			if (temp < 0) throw error_;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return temp;
		}
		catch (const int&)
		{
			std::cout << "����� �� ������ ���� �������������. ��������� ����: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}

int GetNotNegativeInt() 
{
	return GetNotNegativeValue<int>();
}

int GetPositiveInt()
{
	return GetPositiveValue<int>();
}

int GetInt() 
{
	return GetValue<int>();
}

bool SymbolCheck(char c) {
	if (isdigit(static_cast<unsigned char>(c)))
		return true;
	return false;
}