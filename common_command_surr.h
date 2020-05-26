#ifndef COMMAND_SURR
#define COMMAND_SURR

#include "common_command.h"

class CommandSurr : public Command {
public:
	CommandSurr();
	~CommandSurr();
	void operator()();
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
};

#endif // COMMAND_SURR
