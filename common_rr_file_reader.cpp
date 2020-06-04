#include "common_rr_file_reader.h"
#include <exception>
#include <fstream>
	
RRFileReader::RRFileReader(const char* file_name) : actual_line(0) {
	if (!file_name) throw std::exception();
	std::ifstream input(file_name, std::ifstream::in);
	if (!input.is_open()) throw std::exception();
	std::string line;
	while (std::getline(input, line)) {
   		file_lines.push_back(line);
	}
}

RRFileReader::~RRFileReader() {}

std::string RRFileReader::getline() {
	if (actual_line == file_lines.size()) actual_line = 0;
	return file_lines[actual_line++];
}
