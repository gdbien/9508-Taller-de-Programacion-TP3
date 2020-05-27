#ifndef COMMAND_NUMB_H
#define COMMAND_NUMB_H

#include <string>
#include "common_command.h"
#include "common_game.h"
#include "common_message.h"

class CommandNumb : public Command {
private:
	std::string number;
public:
	CommandNumb(const std::string number);
	~CommandNumb();
	bool operator()(Game &game);
	Message callManager(ManagerCommand &mngr) override;
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
};

#endif // COMMAND_NUMB_H
