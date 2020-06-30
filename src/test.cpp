#include "Diary.h"

#include <iostream>

int main(int argc, char* argv[]) {
	Diary d("teste.md");

	for (size_t i = 0; i < 10; ++i) {
		d.add("Mensagem");
	}

	std::cout << "Quantidade de mensagens: " << d.messages_size << std::endl;

	for (size_t i = 0; i < 10; ++i) {
		std::cout << d.messages[i].to_string() << std::endl;
	}

	return 0;
}