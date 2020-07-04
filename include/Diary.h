#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <vector>

struct Diary {
	~Diary();

	std::string filename;
	std::vector<Message*> messages;

	void load();
	void add(const std::string& content);
	std::vector<Message*> search(std::string what);
	void write();
};

#endif