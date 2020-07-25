#include "Config.h"

#include "Util.h"

#include <iostream>
#include <sstream>
#include <fstream>

#define PATH "/home/logica/Downloads/diary/diary.config"

Config::Config() {
	this->file.open(PATH);

	if (!this->file)
		this->create();

	this->file.close();

	this->file.open(PATH);
	check_file_for_error(!this->file);

	getline(file, this->path);
	this->path.erase(0, 5);

	getline(file, this->default_format);
	this->default_format.erase(0, 15);

	this->file.close();
}

void Config::create() {
	std::ofstream file(PATH, std::ios::app);
	check_file_for_error(!file);

	file << "path=diary.md" << std::endl;
	file << "default_format=[%d %t] %m" << std::endl;

	file.close();
}