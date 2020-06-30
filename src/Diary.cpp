#include "Diary.h"

#include "Message.h"
#include "Util.h"

#include <iostream>
#include <sstream>
#include <fstream>

Diary::Diary(const std::string& _filename):
filename(_filename),
messages(nullptr),
messages_size(0),
messages_capacity(1)
{
	messages = new Message[messages_capacity];
	load();
}

Diary::~Diary() {
	write();
	delete[] messages;
}

void Diary::load() {
	std::ifstream file = open_file_for_reading(filename);
	std::string type;
	std::string _date;
	std::string _message;
	
	while (file >> type) {
		if (type == "#") {
			getline(file, _date);
		}
		else if (type == "-") {
			if (messages_size >= messages_capacity)
				resize_messages();

			getline(file, _message);
			messages[messages_size].set(_date, _message);
			messages_size++;
		}
	}

	file.close();
}

void Diary::add(const std::string& message) {
	if (messages_size >= messages_capacity)
		resize_messages();

	messages[messages_size].content = message;
	messages[messages_size].date.set_from_string(get_current_date());
	messages[messages_size].time.set_from_string(get_current_time());
	messages_size++;
}

Message* Diary::search(std::string what) {
	for (size_t i = 0; i < messages_size; ++i) {
		if (messages[i].content.find(what) != std::string::npos) {
			return &messages[i];
		}
	}

	return nullptr;
}

void Diary::resize_messages() {
	messages_capacity *= 2;
	Message *new_messages = new Message[messages_capacity];

	for (size_t i = 0; i < messages_size; ++i) {
		new_messages[i].content = messages[i].content;
		new_messages[i].date.set_from_string(messages[i].date.to_string());
		new_messages[i].time.set_from_string(messages[i].time.to_string());
	}

	delete[] messages;
	messages = new_messages;
}

void Diary::write() {
	std::ofstream file = open_file_for_writing(filename);
	std::string current_date = "";

	for (size_t i = 0; i < messages_size; ++i) {
		if (messages[i].date.to_string() != current_date) {
			current_date = messages[i].date.to_string();
			file << std::endl;
			file << "# ";
			file << current_date;
			file << std::endl;
		}

		file << "- ";
		file << messages[i].time.to_string();
		file << " ";
		file << messages[i].content;
		file << std::endl;
	}
	
	file.close();
}