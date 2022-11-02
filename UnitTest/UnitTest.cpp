#include "pch.h"

#include "CppUnitTest.h"

#include "../Project1/EnterData.h"
#include "../Project1/Algorithm.h"
#include "../Project1/Flight.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

	private:
		dynamic_array start;

		dynamic_array temp1;
		dynamic_array temp2;
		dynamic_array temp3;

		dynamic_array end1;
		dynamic_array end2;
		dynamic_array end3;

	public:
		TEST_METHOD(test)
		{
			/*start = { 0, true, nullptr };
			start.ptr = new Flight[5];
			start.ptr[0] = Flight({ 10, 5 }, week_day[2], plane_type[0], "Москва");
			start.ptr[1] = Flight({ 10, 20 }, week_day[2], plane_type[2], "Москва");
			start.ptr[2] = Flight({ 14, 0 }, week_day[5], plane_type[1], "Минск");
			start.ptr[3] = Flight({ 20, 30 }, week_day[2], plane_type[2], "Новосибирск");
			start.ptr[4] = Flight({ 6, 0 }, week_day[5], plane_type[0], "Волгоград");

			temp1 = GetDestinationList(start, "Москва");
			temp2 = GetWeekdayAndTimeList(start, {10, 10}, 2);
			temp3 = GetWeekdayList(start, 5);

			end1 = { 2, true, nullptr };
			end1.ptr = new Flight[2];
			end2 = { 2, true, nullptr };
			end1.ptr = new Flight[2];
			end3 = { 2, true, nullptr };
			end1.ptr = new Flight[2];


			end1.ptr[0] = start.ptr[0];
			end1.ptr[1] = start.ptr[1];
			end2.ptr[0] = start.ptr[1];
			end2.ptr[1] = start.ptr[3];
			end3.ptr[0] = start.ptr[2];
			end3.ptr[1] = start.ptr[4];

			Assert::IsTrue(end1.size == temp1.size && end1.ptr[0] == temp1.ptr[0] && end1.ptr[0] == temp1.ptr[0]);
			Assert::IsTrue(end2.size == temp2.size && end2.ptr[0] == temp2.ptr[0] && end2.ptr[0] == temp2.ptr[0]);
			Assert::IsTrue(end3.size == temp3.size && end3.ptr[0] == temp2.ptr[0] && end3.ptr[0] == temp3.ptr[0]);*/
		}
	};
};
