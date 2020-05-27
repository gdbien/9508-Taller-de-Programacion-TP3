#ifndef COMMAND_SURR_H
#define COMMAND_SURR_H

#include "common_command.h"
#include "common_message.h"

class CommandSurr : public Command {
public:
	CommandSurr();
	~CommandSurr();
	void operator()();
	Message callManager(ManagerCommand &mngr) override;
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
};

#endif // COMMAND_SURR_H
