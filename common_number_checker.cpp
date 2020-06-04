#include "common_number_checker.h"

NumberChecker::NumberChecker() {}

NumberChecker::~NumberChecker() {}

bool NumberChecker::isGood(const std::string &number,
						   const unsigned int digit_count) {
	return rangeIsGood(number, digit_count) &&
           patternIsGood(number, digit_count);
}

bool NumberChecker::rangeIsGood(const std::string &number,
                                const unsigned int digit_count) {
    return (number.length() == digit_count) ? true : false;
}

bool NumberChecker::patternIsGood(const std::string &number, 
                                  const unsigned int digit_count) {
    for (size_t i = 0; i < number.length() - 1; i++) { 
        for (size_t j = i + 1; j < number.length(); j++) { 
            if (number[i] == number[j]) { 
                return false; 
            } 
        } 
    }
    return true;
}
