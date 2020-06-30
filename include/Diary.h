#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>

struct Diary {
	Diary(const std::string& _filename);
	~Diary();

	std::string filename;
	Message* messages;
	size_t messages_size;
	size_t messages_capacity;

	void load();
	void add(const std::string& message);
	Message* search(std::string what);
	void resize_messages();
	void write();
};

#endif