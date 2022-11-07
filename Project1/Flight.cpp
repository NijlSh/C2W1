#include "Flight.h"

Flight::Flight(time_type dt, std::string dd, std::string pt, std::string dst) : _departure_time(dt), _departure_day(dd), _plane_type(pt), _destination(dst)
{
}

void Flight::SetDepartureTime(time_type value)
{
	_departure_time = value;
}

time_type Flight::GetDepartureTime() 
{
	return _departure_time;
}


void Flight::SetDepartureDay(std::string value)
{
	_departure_day = value;
}

std::string Flight::GetDepartureDay()
{
	return _departure_day;
}


void Flight::SetPlaneType(std::string value)
{
	_plane_type = value;
}

std::string Flight::GetPlaneType() 
{
	return _plane_type;
}


void Flight::SetDestination(std::string value)
{
	_destination = value;
}

std::string Flight::GetDestination()
{
	return _destination;
}


void Flight::ShowFlight(int number) 
{
	std::cout << "Рейс №" << number + 1 << std::endl;
	std::cout << "Время вылета: "; std::cout << std::setfill('0') << std::setw(2) << _departure_time.hour_ << ":" << std::setfill('0') << std::setw(2) << _departure_time.minute_ << std::endl;
	std::cout << "День недели: " << _departure_day << std::endl;
	std::cout << "Пункт назначения: " << _destination << std::endl;
	std::cout << "Тип самолёта: " << _plane_type << std::endl;
}

bool Flight::operator==(const Flight& other) 
{
	return _departure_time.hour_ == other._departure_time.hour_ && _departure_time.minute_ == other._departure_time.minute_ && _departure_day == other._departure_day && _plane_type == other._plane_type && _destination == other._destination;
}

bool Flight::operator!=(const Flight& other)
{
	return !(*this == other);
}