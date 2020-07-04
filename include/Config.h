#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>

struct Config {
	std::ifstream file;
	std::string path;
	std::string default_format;

	void load();
};

#endif