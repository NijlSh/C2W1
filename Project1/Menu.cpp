#include "Menu.h"


inputChoice InputMenu() 
{
	std::cout << "����:" << std::endl << "1 - ���������� ������" << std::endl << "2 - ���������� ����" << std::endl << "3 - �������� ����" << std::endl;
	inputChoice input = static_cast<inputChoice>(CheckMenu(three));
	return input;
}

binaryChoice OutputMenu() 
{
	std::cout << "��������� �������� ������ � �����:" << std::endl << "1 - ���" << std::endl << "2 - ��" << std::endl;
	binaryChoice output = static_cast<binaryChoice>(CheckMenu(two));
	return output;
}

binaryChoice EnterListMenu() 
{
	std::cout << "����������� ������ ������:" << std::endl << "1 - ���" << std::endl << "2 - ��" << std::endl;
	binaryChoice list = static_cast<binaryChoice>(CheckMenu(two));
	return list;
}

listChoice ListMenu()
{
	std::cout << "������� ������:" << std::endl << "1 - ������ �� ������ ����������" << std::endl << "2 - ������ �� ��� ������" << std::endl << "3 - ������ �� ��� ������ � ������" << std::endl;
	listChoice list = static_cast<listChoice>(CheckMenu(three));
	return list;
}

binaryChoice EndProgramMenu() 
{
	std::cout << "��������� ���������" << std::endl << "1 - ���" << std::endl << "2 - ��" << std::endl;
	binaryChoice end_program = static_cast<binaryChoice>(CheckMenu(two));
	return end_program;
}