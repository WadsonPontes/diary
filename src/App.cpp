#include "App.h"

#include <iostream>
#include <vector>

App::App(const std::string& filename) : diary(filename) {

}

int App::run(int argc, char* argv[]) {
	if (argc == 1)
		return this->show_usage(argv[0]);

	std::string action = argv[1];

	if (action == "add") {
		if (argc == 2)
			this->add();
		else
			this->add(argv[2]);
	}
	else if (action == "search") {
		if (argc == 2)
			this->search();
		else
			this->search(argv[2]);
	}
	else if (action == "list") {
		this->list_messages();
	}
	else {
		return this->show_usage(argv[0]);
	}

	return 0;
}

void App::add() {
	std::string message;
	std::cout << "Enter your message: ";
	std::getline(std::cin, message);

	this->add(message);
}

void App::add(const std::string message) {
	this->diary.add(message);
	this->diary.write();
}

void App::search() {
	std::string message;
	std::cout << "Enter your search: ";
	std::getline(std::cin, message);

	this->search(message);
}

void App::search(const std::string message) {
	std::vector<Message*> result = this->diary.search(message);

	if (result.empty())
		std::cout << "No results found" << std::endl;
	else {
		for (auto it : result) {
			std::cout << it->to_string() << std::endl;
		}
	}
}

void App::list_messages() {
	if (this->diary.messages.empty()) {
		std::cout << "No messages found" << std::endl;
	}
	else {
		for (auto it : this->diary.messages) {
			std::cout << it->to_string() << std::endl;
		}
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