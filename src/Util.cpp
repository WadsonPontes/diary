#include "Util.h"

#include <iostream>
#include <ctime>

std::string format_current_date(const std::string& format) {
	std::time_t time = std::time(nullptr);
	char result[1024];

	std::strftime(result,
		          sizeof(result),
		          format.c_str(),
		          std::localtime(&time)
		         );
	
	return std::string(result);
}

std::string get_current_date() {
	return format_current_date("%d/%m/%Y");
}

std::string get_current_time() {
	return format_current_date("%H:%M:%S");
}

std::ifstream open_file_for_reading(std::string filename) {
	std::ofstream create(filename, std::ios::app); // Cria o arquivo se não existir
	create.close();

	std::ifstream file(filename);
	check_file_for_error(!file);

	return file;
}

std::ofstream open_file_for_writing(std::string filename) {
	std::ofstream file(filename);
	
	check_file_for_error(!file);

	return file;
}

void check_file_for_error(bool error) {
	if (error) {
		std::cerr << "Arquivo não existente ou sem permissão de leitura.";
		std::cerr << std::endl;
		exit(1);
	}
}

void replace_all(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);

	while (start_pos != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos = str.find(from);
	}
}

int limparTela() {
	return system(LIMPAR_TELA);
}