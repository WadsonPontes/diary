#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <fstream>

std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();
std::ifstream open_file_for_reading(std::string filename);
std::ofstream open_file_for_writing(std::string filename);
void check_file_for_error(bool error);

#endif