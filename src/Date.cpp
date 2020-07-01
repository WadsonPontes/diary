#include "Date.h"

#include <sstream>

Date::Date():
day(0),
month(0),
year(0)
{
	
}

void Date::set_from_string(const std::string& date) {
	std::stringstream stream(date);
	char discard;

	stream >> this->day;
	stream >> discard;
	stream >> this->month;
	stream >> discard;
	stream >> this->year;
}

std::string Date::to_string() {
	std::stringstream stream;

	if (this->day < 10)
		stream << "0";

	stream << this->day;
	stream << "/";

	if (this->month < 10)
		stream << "0";

	stream << this->month;
	stream << "/";
	stream << this->year;

	return stream.str();
}