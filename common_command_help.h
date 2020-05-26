#ifndef COMMAND_HELP
#define COMMAND_HELP

#include "common_command.h"

class CommandHelp : public Command {
public:
	CommandHelp();
	~CommandHelp();
	void operator()();
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
};

#endif // COMMAND_HELP
