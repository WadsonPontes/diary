#include "Config.h"

#include "Util.h"

#include <iostream>
#include <sstream>
#include <fstream>

Config::Config() {
	this->file.open("diary.config");

	if (!this->file)
		this->create();

	this->file.close();

	this->file.open("diary.config");
	check_file_for_error(!this->file);

	getline(file, this->path);
	this->path.erase(0, 5);

	getline(file, this->default_format);
	this->default_format.erase(0, 15);

	this->file.close();
}

void Config::create() {
	std::ofstream file("diary.config", std::ios::app);
	check_file_for_error(!file);

	file << "path=diary.md" << std::endl;
	file << "default_format=[%d %t] %m" << std::endl;

	file.close();
}