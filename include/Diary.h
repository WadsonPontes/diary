#ifndef DIARY_H
#define DIARY_H

#include "Message.h"

#include <string>
#include <vector>

class Diary {
	public:
		std::string filename;
		std::vector<Message*> messages;

		~Diary();

		void load();
		void add(const std::string& content);
		void edit(int id, std::string message);
		void remove(int id);
		std::vector<Message*> search(std::string what);
		void write();
};

#endif