#include "Diary.h"

#include "Message.h"
#include "Util.h"

#include <iostream>
#include <sstream>
#include <fstream>

Diary::Diary(const std::string& filename):
filename(filename)
{
	this->load();
}

Diary::~Diary() {
	this->write();
}

void Diary::load() {
	std::ifstream file = open_file_for_reading(this->filename);
	std::string type;
	std::string date;
	std::string content;
	
	while (file >> type) {
		if (type == "#") {
			getline(file, date);
		}
		else if (type == "-") {
			getline(file, content);

			Message *message = new Message(date, content);

			this->messages.push_back(message);
		}
	}

	file.close();
}

void Diary::add(const std::string& content) {
	Message *message = new Message(get_current_date(), get_current_time(), content);

	this->messages.push_back(message);
}

std::vector<Message*> Diary::search(std::string what) {
	std::vector<Message*> result;

	for (auto it : this->messages) {
		if (it->content.find(what) != std::string::npos) {
			result.push_back(it);
		}
	}

	return result;
}

void Diary::write() {
	std::ofstream file = open_file_for_writing(this->filename);
	std::string current_date = "";

	for (auto it : this->messages) {
		if (it->date.to_string() != current_date) {
			current_date = it->date.to_string();
			file << std::endl;
			file << "# ";
			file << current_date;
			file << std::endl;
		}

		file << "- ";
		file << it->time.to_string();
		file << " ";
		file << it->content;
		file << std::endl;
	}
	
	file.close();
}