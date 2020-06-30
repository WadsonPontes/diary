#include "Message.h"

#include <sstream>

void Message::set(const std::string& _date, const std::string& _message) {
	std::stringstream stream(_message);
	std::string _time;
	char discard;

	date.set_from_string(_date);

	stream >> _time;
	time.set_from_string(_time);

	stream >> std::noskipws >> discard;
	std::getline(stream, content);
}

void Message::set_from_string(const std::string& message) {
	std::stringstream stream(message);
	std::string temp;
	char discard;

	stream >> temp;
	date.set_from_string(temp);

	stream >> temp;
	time.set_from_string(temp);

	stream >> std::noskipws >> discard;
	std::getline(stream, content);
}

std::string Message::to_string() {
	return "[" + date.to_string() + " " + time.to_string() + "] " + content;
}