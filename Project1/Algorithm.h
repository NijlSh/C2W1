#pragma once
#include "Items.h"
#include "Flight.h"

#include <string>
#include <iostream>

void DestinationList(const dynamic_array flight);
void WeekdayAndTimeList(const dynamic_array flight);
void WeekdayList(const dynamic_array flight);

dynamic_array GetDestinationList(const dynamic_array flight, std::string value);


dynamic_array GetWeekdayAndTimeList(const dynamic_array flight, time_type temp_time, int number);


dynamic_array GetWeekdayList(const dynamic_array flight, int number);