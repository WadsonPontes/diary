#include "App.h"

#include "Util.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

App::App() {
	this->diary.filename = this->config.path;
	this->diary.load();
}

int App::run(int argc, char* argv[]) {
	if (argc == 1)
		return this->interactive();

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
		else if (argc == 3)
			this->search(argv[2]);
		else
			this->search(argv[2], argv[3]);
	}
	else if (action == "list") {
		if (argc == 2)
			this->list_messages();
		else
			this->list_messages(argv[2]);
	}
	else if (action == "interactive") {
		return this->interactive();
	}
	else {
		return this->show_usage(argv[0]);
	}

	return 0;
}

void App::add() {
	std::string message;

	std::getline(std::cin, message);

	this->add(message);
}

void App::add(const std::string message) {
	this->diary.add(message);
	this->diary.write();
}

void App::remove() {
	std::string message;

	std::getline(std::cin, message);

	this->remove(message);
}

void App::remove(const std::string message) {
	this->diary.remove(std::stoi(message));
	this->diary.write();
}

void App::search() {
	std::string message;

	std::getline(std::cin, message);

	this->search(message, this->config.default_format);
}

void App::search(const std::string message) {
	this->search(message, this->config.default_format);
}

void App::search(const std::string message, const std::string format) {
	std::vector<Message*> result = this->diary.search(message);

	limparTela();
	std::cout << "[RESULT FOR][" << message << "]" << std::endl << std::endl;

	if (result.empty())
		std::cout << "No results found..." << std::endl;
	else {
		for (auto it : result) {
			std::cout << it->to_string(format) << std::endl;
		}
	}
}

void App::list_messages() {
	this->list_messages(this->config.default_format);
}

void App::list_messages(const std::string format) {
	if (this->diary.messages.empty()) {
		std::cout << "No messages found..." << std::endl;
	}
	else {
		for (auto it : this->diary.messages) {
			std::cout << it->to_string(format) << std::endl;
		}
	}
}

void App::list_with_id() {
	this->list_with_id(this->config.default_format);
}

void App::list_with_id(const std::string format) {
	if (this->diary.messages.empty()) {
		std::cout << "No messages found..." << std::endl;
	}
	else {
		size_t i = 0;

		for (auto it : this->diary.messages) {
			std::cout << "[" << i << "] " << it->to_string(format) << std::endl;
			i++;
		}
	}
	std::cout << std::endl;
}

int App::interactive() {
	std::string action;

	do {
		limparTela();

		std::cout << "[SELECT AN ACTION]" << std::endl << std::endl;

		std::cout << "[Enter 1] LIST" << std::endl;
		std::cout << "[Enter 2] ADD" << std::endl;
		std::cout << "[Enter 3] REMOVE" << std::endl;
		std::cout << "[Enter 4] SEARCH" << std::endl;
		std::cout << "[Enter 0] EXIT" << std::endl << std::endl;

		std::cout << "[ACTION]";

		getline(std::cin, action);

		if (action == "1") {
			limparTela();
			std::cout << "[ALL MESSAGES]" << std::endl << std::endl;

			this->list_messages();

			std::cout << std::endl << "[BACK]";
			getchar();
		}
		else if (action == "2") {
			limparTela();
			std::cout << "[ENTER YOUR MESSAGE]" << std::endl << std::endl;

			std::cout << std::endl << "[MESSAGE]";

			this->add();
		}
		else if (action == "3") {
			limparTela();
			this->list_with_id();

			std::cout << "[ENTER THE ID]" << std::endl;

			std::cout << std::endl << "[ID]";

			this->remove();
		}
		else if (action == "4") {
			limparTela();
			std::cout << "[ENTER YOUR SEARCH]" << std::endl << std::endl;

			std::cout << std::endl << "[SEARCH]";

			this->search();

			std::cout << std::endl << "[BACK]";
			getchar();
		}
		else if (action != "0") {
			limparTela();
			std::cout << "[INVALID ACTION]" << std::endl << std::endl;

			std::cout << std::endl << "[BACK]";
			getchar();
		}

	} while (action != "0");

	limparTela();

	return 0;
}

int App::show_usage(const std::string codename) {
	std::cout << "[Possible commands]" << std::endl << std::endl;
	std::cout << codename << std::endl;
	std::cout << codename << " add" << std::endl;
	std::cout << codename << " add <message>" << std::endl;
	std::cout << codename << " search" << std::endl;
	std::cout << codename << " search <message>" << std::endl;
	std::cout << codename << " search <message> <format>" << std::endl;
	std::cout << codename << " list" << std::endl;
	std::cout << codename << " list <format>" << std::endl;
	std::cout << codename << " interactive" << std::endl;
	return 0;
}