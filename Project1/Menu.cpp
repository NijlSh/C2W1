#include "Menu.h"


inputChoice InputMenu() 
{
	std::cout << "Меню:" << std::endl << "1 - завершение работы" << std::endl << "2 - консольный ввод" << std::endl << "3 - файловый ввод" << std::endl;
	inputChoice input = static_cast<inputChoice>(CheckMenu(three));
	return input;
}

binaryChoice OutputMenu() 
{
	std::cout << "Сохранить исходные данные в файле:" << std::endl << "1 - нет" << std::endl << "2 - да" << std::endl;
	binaryChoice output = static_cast<binaryChoice>(CheckMenu(two));
	return output;
}

binaryChoice EnterListMenu() 
{
	std::cout << "Рассмотреть список рейсов:" << std::endl << "1 - нет" << std::endl << "2 - да" << std::endl;
	binaryChoice list = static_cast<binaryChoice>(CheckMenu(two));
	return list;
}

listChoice ListMenu()
{
	std::cout << "Вывести список:" << std::endl << "1 - список по пункту назначения" << std::endl << "2 - список по дню недели" << std::endl << "3 - список по дню недели и времен" << std::endl;
	listChoice list = static_cast<listChoice>(CheckMenu(three));
	return list;
}

binaryChoice EndProgramMenu() 
{
	std::cout << "Закончить программу" << std::endl << "1 - нет" << std::endl << "2 - да" << std::endl;
	binaryChoice end_program = static_cast<binaryChoice>(CheckMenu(two));
	return end_program;
}