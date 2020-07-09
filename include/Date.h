#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
	public:
		unsigned day;
		unsigned month;
		unsigned year;

		Date();

		void set_from_string(const std::string& date);
		std::string to_string();
};

#endif