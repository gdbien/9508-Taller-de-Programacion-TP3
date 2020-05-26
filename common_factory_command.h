#ifndef FACTORY_COMMAND_H
#define FACTORY_COMMAND_H

#include <exception>
#include <string>
#include "common_command.h"

class UnknownCommandException : public std::exception {
public:
	const char *what() const throw();
};

class FactoryCommand {
public:
	FactoryCommand();
	~FactoryCommand();
	static Command* create(const std::string &type);
};

#endif // FACTORY_COMMAND_H
