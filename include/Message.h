#ifndef MESSAGE_H
#define MESSAGE_H

#include "Date.h"
#include "Time.h"

#include <string>

struct Message {
	std::string content;
	Date date;
	Time time;

	void set(const std::string& _date, const std::string& _message);
	void set_from_string(const std::string& message);
	std::string to_string();
};

#endif