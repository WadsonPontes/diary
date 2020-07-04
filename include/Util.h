#ifndef UTIL_H
#define UTIL_H

#ifdef __WIN32__
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

#include <string>
#include <fstream>

std::string format_current_date(const std::string& format);
std::string get_current_date();
std::string get_current_time();
std::ifstream open_file_for_reading(std::string filename);
std::ofstream open_file_for_writing(std::string filename);
void check_file_for_error(bool error);
void replace_all(std::string& str, const std::string& from, const std::string& to);
int limparTela();

#endif