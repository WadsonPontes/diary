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
	limparTela();

	if (argc == 1)
		return this->interactive();

	std::string action = argv[1];

	if (action == "interactive") {
		return this->interactive();
	}
	else if (action == "add") {
		if (argc == 2)
			this->add();
		else
			this->add(argv[2]);
	}
	else if (action == "edit") {
		if (argc == 2)
			this->edit();
		else if (argc == 3) {
			try {
				size_t id = std::stoi(argv[2]);

				this->edit(id);
			}
			catch (...) {
				this->edit(argv[2]);
			}
		}
		else if (argc == 4) {
			try {
				size_t id = std::stoi(argv[2]);

				this->edit(id, argv[3], this->config.default_format);
			}
			catch (...) {
				invalid_action();
			}
		}
		else {
			try {
				size_t id = std::stoi(argv[2]);

				this->edit(id, argv[3], argv[4]);
			}
			catch (...) {
				invalid_action();
			}
		}
	}
	else if (action == "remove") {
		if (argc == 2)
			this->remove();
		else {
			try {
				size_t id = std::stoi(argv[2]);

				this->remove(id, this->config.default_format);
			}
			catch (...) {
				this->remove(argv[2]);
			}
		}
	}
	else if (action == "list") {
		if (argc == 2)
			this->list_messages();
		else
			this->list_messages(argv[2]);
	}
	else if (action == "search") {
		if (argc == 2)
			this->search();
		else if (argc == 3)
			this->search(argv[2]);
		else
			this->search(argv[2], argv[3]);
	}
	else {
		return this->show_usage(argv[0]);
	}

	limparTela();

	return 0;
}

void App::add() {
	std::string message;

	std::cout << "[ENTER YOUR MESSAGE]" << std::endl << std::endl;
	std::cout << "[Enter 0] BACK" << std::endl << std::endl;
	std::cout << "[MESSAGE]";

	std::getline(std::cin, message);
	limparTela();

	if (message != "0" && message != "")
		this->add(message);
}

void App::add(const std::string message) {
	this->diary.add(message);
	this->diary.write();
}

void App::edit() {
	this->edit(this->config.default_format);
}

void App::edit(const std::string format) {
	std::string id;

	this->list_with_id(format);
	
	std::cout << "[ENTER THE ID]" << std::endl;
	std::cout << std::endl << "[ID]";

	std::getline(std::cin, id);
	limparTela();

	if (id != "0" && id != "") {
		try {
			size_t i = std::stoi(id);

			this->edit(i, format);
		}
		catch (...) {
			invalid_action();
		}
	}
}

void App::edit(size_t id) {
	this->edit(id, this->config.default_format);
}

void App::edit(size_t id, const std::string format) {
	std::string new_message;

	if (id < 1 || id > this->diary.messages.size())
		invalid_action();
	else {
		std::cout << "[OLD] ";
		std::cout << this->diary.messages[id-1]->to_string(format) << std::endl << std::endl;
		std::cout << "[WRITE THE NEW MESSAGE]" << std::endl << std::endl;
		std::cout << "[Enter 0] CANCEL" << std::endl << std::endl;
		std::cout << "[MESSAGE]";

		std::getline(std::cin, new_message);
		limparTela();

		this->edit(id, new_message, format);
	}
}

void App::edit(size_t id, const std::string message, const std::string format) {
	if (id < 1 || id > this->diary.messages.size())
		invalid_action();
	else if (message != "0" && message != "") {
		--id;
		this->diary.edit(id, message);
		this->diary.write();
	}
}

void App::remove() {
	this->remove(this->config.default_format);
}

void App::remove(const std::string format) {
	std::string id;

	this->list_with_id(format);

	std::cout << "[ENTER THE ID]" << std::endl;
	std::cout << std::endl << "[ID]";

	std::getline(std::cin, id);
	limparTela();

	if (id != "0" && id != "") {
		try {
			size_t i = std::stoi(id);

			this->remove(i, format);
		}
		catch (...) {
			invalid_action();
		}
	}
}

void App::remove(size_t id, const std::string format) {
	if (id < 1 || id > this->diary.messages.size())
		invalid_action();
	else {
		--id;
		this->diary.remove(id);
		this->diary.write();
	}
}

void App::search() {
	std::string message;

	std::cout << "[ENTER YOUR SEARCH]" << std::endl << std::endl;
	std::cout << "[Enter 0] BACK" << std::endl << std::endl;
	std::cout << "[SEARCH]";

	std::getline(std::cin, message);
	limparTela();

	this->search(message, this->config.default_format);
}

void App::search(const std::string message) {
	this->search(message, this->config.default_format);
}

void App::search(const std::string message, const std::string format) {
	std::vector<Message*> result = this->diary.search(message);
	size_t number_messages = 0;

	if (message != "0" && message != "") {
		std::cout << "[RESULT FOR][" << message << "]" << std::endl << std::endl;

		if (result.empty())
			std::cout << "No results found..." << std::endl;
		else {
			for (auto it : result) {
				std::cout << it->to_string(format) << std::endl;
				number_messages++;
			}
			std::cout << "Number of messages: " << number_messages << std::endl;
		}
		back_button();
	}
}

void App::list_messages() {
	this->list_messages(this->config.default_format);
}

void App::list_messages(const std::string format) {
	size_t number_messages = 0;

	std::cout << "[ALL MESSAGES]" << std::endl << std::endl;

	if (this->diary.messages.empty()) {
		std::cout << "No messages found..." << std::endl;
	}
	else {
		for (auto it : this->diary.messages) {
			std::cout << it->to_string(format) << std::endl;
			number_messages++;
		}
	}

	std::cout << "Number of messages: " << number_messages << std::endl;
	back_button();
}

void App::list_with_id() {
	this->list_with_id(this->config.default_format);
}

void App::list_with_id(const std::string format) {
	int n = size(this->diary.messages.size());

	if (this->diary.messages.empty()) {
		std::cout << "No messages found..." << std::endl;
	}
	else {
		size_t id = 1;

		for (auto it : this->diary.messages) {
			std::cout << "[Enter " << spaces(n - size(id));
			std::cout << id << "] " << it->to_string(format) << std::endl;
			id++;
		}
	}
	std::cout << "[Enter " << spaces(n - 1);
	std::cout << "0] BACK" << std::endl << std::endl;
}

int App::interactive() {
	std::string action;

	do {
		limparTela();
		std::cout << "[SELECT AN ACTION]" << std::endl << std::endl;

		std::cout << "[Enter 1] ADD" << std::endl;
		std::cout << "[Enter 2] EDIT" << std::endl;
		std::cout << "[Enter 3] REMOVE" << std::endl;
		std::cout << "[Enter 4] LIST" << std::endl;
		std::cout << "[Enter 5] SEARCH" << std::endl;
		std::cout << "[Enter 0] EXIT" << std::endl << std::endl;

		std::cout << "[ACTION]";

		getline(std::cin, action);
		limparTela();

		if (action == "1") {
			this->add();
		}
		else if (action == "2") {
			this->edit();
		}
		else if (action == "3") {
			this->remove();
		}
		else if (action == "4") {
			this->list_messages();
		}
		else if (action == "5") {
			this->search();
		}
		else if (action != "0" && action != "") {
			invalid_action();
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