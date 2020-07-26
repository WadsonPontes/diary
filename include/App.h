#ifndef APP_H
#define APP_H

#include "Diary.h"
#include "Config.h"

#include <iostream>
#include <string>

class App {
	public:
		Config config;
		Diary diary;

		App();

		int run(int argc, char* argv[]);
		void add();
		void add(const std::string message);
		void edit();
		void edit(const std::string message);
		void edit(size_t id, const std::string message);
		void remove();
		void remove(const std::string message);
		void search();
		void search(const std::string message);
		void search(const std::string message, const std::string format);
		void list_messages();
		void list_messages(const std::string format);
		void list_with_id();
		void list_with_id(const std::string format);
		int interactive();
		int show_usage(const std::string codename);
};

#endif