#include "pch.h"

#include "CppUnitTest.h"

#include "../Project1/Check.cpp"
#include "../Project1/Algorithm.cpp"
#include "../Project1/Flight.h"
#include "../Project1/Flight.cpp"
#include "../Project1/Items.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		Flight temp_start[5] =
		{
			Flight({ 9, 5 }, week_day[2], plane_type[0], "Москва"),
			Flight({ 10, 20 }, week_day[2], plane_type[2], "Москва"),
			Flight({ 14, 0 }, week_day[5], plane_type[1], "Минск"),
			Flight({ 20, 30 }, week_day[2], plane_type[2], "Новосибирск"),
			Flight({ 6, 0 }, week_day[5], plane_type[0], "Волгоград")
		};

		dynamic_array start_list = { 5, true, temp_start };

		Flight temp_true1[2]
		{
			Flight({ 9, 5 }, week_day[2], plane_type[0], "Москва"),
			Flight({ 10, 20 }, week_day[2], plane_type[2], "Москва")
		};

		dynamic_array test1_true_list = { 2, true, temp_true1 };

		Flight temp_true2[2]
		{
			Flight({ 10, 20 }, week_day[2], plane_type[2], "Москва"),
			Flight({ 20, 30 }, week_day[2], plane_type[2], "Новосибирск")
		};

		dynamic_array test2_true_list = { 2, true, temp_true2 };

		Flight temp_true3[2]
		{
			Flight({ 14, 0 }, week_day[5], plane_type[1], "Минск"),
			Flight({ 6, 0 }, week_day[5], plane_type[0], "Волгоград")
		};

		dynamic_array test3_true_list = { 2, true, temp_true3 };

	public:
		bool equivalentFlightList(Flight* list1, Flight* list2, int size)
		{
			for (int i = 0; i < size; i++) {
				if (list1[i] != list2[i]) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(test1)
		{
			dynamic_array end_list_test = { 0, true, nullptr };
			end_list_test = GetDestinationList(start_list, "Москва");
			Assert::IsTrue(equivalentFlightList(test1_true_list.ptr, end_list_test.ptr, 2));
		}

		TEST_METHOD(test2)
		{
			dynamic_array end_list_test = { 0, true, nullptr };
			end_list_test = GetWeekdayAndTimeList(start_list, { 10, 10 }, 2);
			Assert::IsTrue(equivalentFlightList(test2_true_list.ptr, end_list_test.ptr, 2));
		}

		TEST_METHOD(test3)
		{
			dynamic_array end_list_test = { 0, true, nullptr };
			end_list_test = GetWeekdayList(start_list, 5);
			Assert::IsTrue(equivalentFlightList(test3_true_list.ptr, end_list_test.ptr, 2));
		}
	};
};
