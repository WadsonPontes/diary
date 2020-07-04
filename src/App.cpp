#include "App.h"

#include "Util.h"

#include <iostream>
#include <vector>
#include <sstream>

App::App() {
	config.load();
	diary.filename = config.path;
	diary.load();
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
		if (argc == 2)
			this->list_messages();
		else
			this->list_messages(argv[2]);
	}
	else if (action == "interactive") {
		this->interactive();
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
			std::cout << it->to_string(this->config.default_format) << std::endl;
		}
	}
}

void App::list_messages() {
	this->list_messages(this->config.default_format);
}

void App::list_messages(const std::string format) {
	if (this->diary.messages.empty()) {
		std::cout << "No messages found" << std::endl;
	}
	else {
		for (auto it : this->diary.messages) {
			std::cout << it->to_string(format) << std::endl;
		}
	}
}

void App::interactive() {
	std::string action;

	do {
		limparTela();
		std::cout << "Diário 1.0" << std::endl << std::endl;

		std::cout << "Selecione uma ação:" << std::endl << std::endl;

		std::cout << "1) Listar mensagens" << std::endl;
		std::cout << "2) Adicionar nova mensagem" << std::endl;
		std::cout << "3) Pesquisar" << std::endl << std::endl;

		std::cout << "0) Finalizar" << std::endl;

		std::cout << ">";

		getline(std::cin, action);

		if (action == "1")
			this->list_messages();
		else if (action == "2")
			this->add();
		else if (action == "3")
			this->search();
		else if (action != "0")
			std::cout << "Digite um comando valido" << std::endl;

		if (action != "0" && action != "2")
			getchar();

	} while (action != "0");
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