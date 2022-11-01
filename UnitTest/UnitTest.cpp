#include "pch.h"

#include "CppUnitTest.h"

#include "../Project1/EnterData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

	private:
		Flight flight1;
		Flight flight2;
		Flight flight3;

	public:

		TEST_METHOD(BubleTest)
		{
			flight1 = Flight::Flight({ 10, 0 }, "Понедельник", "Airbus A380", "Moskau");
			flight2 = Flight::Flight({ 10, 0 }, "Вторник", "Airbus A380", "Moskau");
			flight3 = Flight::Flight({ 10, 0 }, "Пятница", "Airbus A380", "Moskau");
		}
	};
};
