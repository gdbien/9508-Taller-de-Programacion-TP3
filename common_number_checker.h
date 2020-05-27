#ifndef NUMBER_CHECKER_H
#define NUMBER_CHECKER_H

#include <cstddef>
#include <string>

class NumberChecker {
public:
	NumberChecker();
	~NumberChecker();
	static bool isGood(const std::string &number, const size_t digit_count);
};

#endif // NUMBER_CHECKER_H