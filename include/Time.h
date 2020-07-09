#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
	public:
		unsigned hour;
		unsigned minute;
		unsigned second;

		Time();

		void set_from_string(const std::string& time);
		std::string to_string();
};

#endif