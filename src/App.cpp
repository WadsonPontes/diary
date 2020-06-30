#include "App.h"

#include <iostream>

App::App(const std::string& filename) : diary(filename) {

}

int App::run(int argc, char* argv[]) {
	if (argc == 1)
		return show_usage(argv[0]);

	std::string action = argv[1];

	if (action == "add") {
		if (argc == 2)
			add();
		else
			add(argv[2]);
	}
	else if (action == "search") {
		if (argc == 2)
			search();
		else
			search(argv[2]);
	}
	else if (action == "list") {
		list_messages();
	}
	else {
		return show_usage(argv[0]);
	}

	return 0;
}

void App::add() {
	std::string message;
	std::cout << "Enter your message: ";
	std::getline(std::cin, message);

	add(message);
}

void App::add(const std::string message) {
	diary.add(message);
	diary.write();
}

void App::search() {
	std::string message;
	std::cout << "Enter your search: ";
	std::getline(std::cin, message);

	search(message);
}

void App::search(const std::string message) {
	Message* result = diary.search(message);

	if (result == nullptr)
		std::cout << "No results found" << std::endl;
	else
		std::cout << result->to_string() << std::endl;
}

void App::list_messages() {
	for (size_t i = 0; i < diary.messages_size; ++i) {
		std::cout << diary.messages[i].to_string() << std::endl;
	}
}

int App::show_usage(const std::string codename) {
	std::cout << "Use: " << codename << " add" << std::endl;
	std::cout << "Or" << std::endl;
	std::cout << "Use: " << codename << " add <message>" << std::endl;
	std::cout << "Or" << std::endl;
	std::cout << "Use: " << codename << " search" << std::endl;
	std::cout << "Or" << std::endl;
	std::cout << "Use: " << codename << " search <message>" << std::endl;
	std::cout << "Or" << std::endl;
	std::cout << "Use: " << codename << " list" << std::endl;
	return 0;
}