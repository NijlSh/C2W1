#include "GetFromFile.h"

int getLineI(std::ifstream& file)
{
	std::string temp_s = "";
	int temp_i = 0;
	try
	{
		std::getline(file, temp_s);
	}
	catch (const std::exception&)
	{
		std::cout << "Ошибка при чтении информации из файла." << std::endl;
		throw std::exception();
	}
	try
	{
		temp_i = stoi(temp_s);
		if (temp_i <= 0) throw std::exception();
		else return temp_i;
	}
	catch (int)
	{
		std::cout << "Некорректный формат данных." << std::endl;
		throw std::exception();
	}
}

double getLineD(std::ifstream& file)
{
	std::string temp_s = "";
	double temp_d = 0.0;
	try
	{
		std::getline(file, temp_s);
	}
	catch (const std::exception&)
	{
		std::cout << "Ошибка при чтении информации из файла." << std::endl;
		throw std::exception();
	}
	try
	{
		temp_d = stod(temp_s);
		if (temp_d < 0) throw  std::exception();
		else return temp_d;
	}
	catch (int)
	{
		std::cout << "Некорректный формат данных." << std::endl;
		throw std::exception();
	}
}

std::string getLineS(std::ifstream& file)
{
	std::string temp_1 = "";
	try
	{
		std::getline(file, temp_1);
		return temp_1;
	}
	catch (const std::exception&)
	{
		std::cout << "Ошибка при чтении информации из файла." << std::endl;
		throw std::exception();
	}
}