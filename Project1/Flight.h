#pragma once

#include "Check.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

const int max_hour = 24;
const int max_minute = 60;
const int max_plane = 3;
const int max_day = 7;

const std::string week_day[max_day] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
const std::string plane_type[max_plane] = { "Airbus A380",
									"Boeing 787 Dreamliner",
									"Туполев Ту-154" };

typedef struct 
{
	int hour_;
	int minute_;
} time_type;

class Flight 
{
private:
	time_type _departure_time;
	std::string _departure_day;
	std::string _plane_type;
	std::string _destination;
public:
	Flight() = default;
	Flight(time_type dt, std::string dd, std::string pt, std::string dst);

	void SetDepartureTime(time_type value);
	time_type GetDepartureTime();

	void SetDepartureDay(std::string value);
	std::string GetDepartureDay();

	void SetPlaneType(std::string value);
	std::string GetPlaneType();

	void SetDestination(std::string value);
	std::string GetDestination();

	void ShowFlight(int number);
};