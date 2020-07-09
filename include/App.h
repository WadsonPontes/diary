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
		void search();
		void search(const std::string message);
		void list_messages();
		void list_messages(const std::string format);
		void interactive();
		int show_usage(const std::string codename);
};

#endif