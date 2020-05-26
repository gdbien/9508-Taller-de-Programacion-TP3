#include "common_rr_file_reader.h"
#include <exception>

RRFileReader::RRFileReader(const char* file_name) {
	if (!file_name) throw std::exception();
	input = std::ifstream(file_name, std::ifstream::in);
	if (!input.is_open()) throw std::exception();
}

RRFileReader::~RRFileReader() {}

std::string RRFileReader::getline() {
	std::string line;
	if (!std::getline(input, line)) {
		input.clear();
  		input.seekg(0);
  		std::getline(input, line);
	}
	return line;
}