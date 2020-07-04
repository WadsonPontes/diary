#include "Config.h"

#include "Util.h"

#include <iostream>
#include <sstream>
#include <fstream>

void Config::load() {
	this->file.open("diary.config");

	if (!this->file) {
		std::ofstream create("diary.config", std::ios::app);
		check_file_for_error(!create);

		create << "path=diary.md" << std::endl;
		create << "default_format=%d %t: %m" << std::endl;

		create.close();
	}

	this->file.close();

	this->file.open("diary.config");
	check_file_for_error(!this->file);

	getline(file, this->path);
	this->path.erase(0, 5);

	getline(file, this->default_format);
	this->default_format.erase(0, 15);

	this->file.close();
}