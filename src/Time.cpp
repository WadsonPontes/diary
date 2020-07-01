#include "Time.h"

#include <sstream>

Time::Time():
hour(0),
minute(0),
second(0)
{
	
}

void Time::set_from_string(const std::string& time) {
	std::stringstream stream(time);
	char discard;

	stream >> this->hour;
	stream >> discard;
	stream >> this->minute;
	stream >> discard;
	stream >> this->second;
}

std::string Time::to_string() {
	std::stringstream stream;

	if (this->hour < 10)
		stream << "0";

	stream << this->hour;
	stream << ":";

	if (this->minute < 10)
		stream << "0";

	stream << this->minute;
	stream << ":";

	if (this->second < 10)
		stream << "0";

	stream << this->second;

	return stream.str();
}