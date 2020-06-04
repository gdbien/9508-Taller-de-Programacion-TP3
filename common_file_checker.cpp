#include "common_file_checker.h"
#include <fstream>
#include <string>
#include "common_number_checker.h"

FileChecker::FileChecker() {}

FileChecker::~FileChecker() {}

int FileChecker::isGood(const char *file_name,
                        const unsigned int &digit_count) {
	int ret = 0;
	if (!file_name) throw std::exception();
	std::ifstream input(file_name, std::ifstream::in);
	if (!input.is_open()) throw std::exception();
	std::string number;
    while (std::getline(input, number)) {
    	if (!NumberChecker::patternIsGood(number, digit_count)) {
    		ret = F_CHK_INVL_PATRN;
    		break;
    	}
    	if (!NumberChecker::rangeIsGood(number, digit_count)) {
    		ret = F_CHK_INVL_RANGE;
    		break;
    	}
  	}
  	return ret;
}
