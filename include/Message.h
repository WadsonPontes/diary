#ifndef MESSAGE_H
#define MESSAGE_H

#include "Date.h"
#include "Time.h"

#include <string>

class Message {
	public:
		std::string content;
		Date date;
		Time time;

		Message(const std::string& date, const std::string& content);
		Message(const std::string& date, const std::string& time, const std::string& content);

		void set_from_string(const std::string& message);
		std::string to_string(std::string format);
};

#endif