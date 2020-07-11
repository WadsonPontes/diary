#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>

class Config {
	public:
		std::ifstream file;
		std::string path;
		std::string default_format;

		Config();
		void create();
};

#endif