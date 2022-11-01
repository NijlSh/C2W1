#include "FileOutput.h"

bool FileOutput(dynamic_array temp) 
{
	std::ofstream file;
	file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	bool is_stream_opened = false;
	std::string file_name = "";

	do
	{
		try
		{
			file_name = GetFileName(output);
			file.open(file_name);
			is_stream_opened = true;
		}
		catch (const std::exception&)
		{
			std::cout << "������ ��� ������� ������� ����." << std::endl;
			continue;
		}
	} while (!is_stream_opened);

	try 
	{
		file << temp.size << std::endl;

		for (int i = 0; i < temp.size; i++) 
		{
			file << temp.ptr[i].GetDepartureDay() << std::endl;
			time_type value = temp.ptr[i].GetDepartureTime();
			file << value.hour_ << std::endl;
			file << value.minute_ << std::endl;
			file << temp.ptr[i].GetDestination() << std::endl;
			file << temp.ptr[i].GetPlaneType() << std::endl;
		}

		std::cout << "������ ������� ���������." << std::endl;
		file.close();
		return true;
	}
	catch(std::exception&)
	{
		std::cout << "������ ��� ������ ���������� � ����." << std::endl;
		file.close();
		return false;
	}
}