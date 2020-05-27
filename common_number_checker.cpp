#include "common_number_checker.h"

NumberChecker::NumberChecker() {}

NumberChecker::~NumberChecker() {}

bool NumberChecker::isGood(const std::string &number,
						   const size_t digit_count) {
	if (number.length() != digit_count) return false;
	for (size_t i = 0; i < number.length() - 1; i++) { 
        for (size_t j = i + 1; j < number.length(); j++) { 
            if (number[i] == number[j]) { 
                return false; 
            } 
        } 
    }
    return true;
}


