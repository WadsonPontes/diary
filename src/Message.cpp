#include "Message.h"

#include "Util.h"

#include <sstream>

Message::Message(const std::string& date, const std::string& content) {
	std::stringstream stream(content);
	std::string time;
	char discard;

	this->date.set_from_string(date);

	stream >> time;
	this->time.set_from_string(time);

	stream >> std::noskipws >> discard;
	std::getline(stream, this->content);
}

Message::Message(const std::string& date, const std::string& time, const std::string& content) {
	this->date.set_from_string(date);
	this->time.set_from_string(time);
	this->content = content;
}

void Message::set_from_string(const std::string& message) {
	std::stringstream stream(message);
	std::string temp;
	char discard;

	stream >> temp;
	this->date.set_from_string(temp);

	stream >> temp;
	this->time.set_from_string(temp);

	stream >> std::noskipws >> discard;
	std::getline(stream, this->content);
}

std::string Message::to_string(std::string format) {
	std::string message = format;

	replace_all(message, "%d", this->date.to_string());
	replace_all(message, "%t", this->time.to_string());
	replace_all(message, "%m", this->content);

	return message;
}