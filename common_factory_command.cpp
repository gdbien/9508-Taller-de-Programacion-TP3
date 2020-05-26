#include "common_factory_command.h"
#include <limits.h>
#include <algorithm>
#include "common_command_surr.h"
#include "common_command_help.h"
#include "common_command_numb.h"

#define SURRENDER "RENDIRSE"
#define HELP "AYUDA"

const char* UnknownCommandException::what() const throw(){
	return "Unknown command type";
}

FactoryCommand::FactoryCommand() {}

FactoryCommand::~FactoryCommand() {}

Command* FactoryCommand::create(const std::string &type) {
	if (type == SURRENDER) {
		return new CommandSurr();	
	} else if (type == HELP) {
		return new CommandHelp();
	} else {
		if (!std::all_of(type.begin(), type.end(), ::isdigit)) {
			throw UnknownCommandException();
		}
		try {
			int number = stoi(type);
			if (number > USHRT_MAX) {
				throw UnknownCommandException();
			}
		} catch (...) {
			throw UnknownCommandException();		
		}
		return new CommandNumb(type);
	}
}

