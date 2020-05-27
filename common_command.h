#ifndef COMMAND_H
#define COMMAND_H

#include "common_protocolable.h"
#include "common_types_command.h"

class ManagerCommand;
class Message;

class Command : public Protocolable {
public:
	Command();
	virtual ~Command();
	virtual Message callManager(ManagerCommand &mngr) = 0;
};

#endif // COMMAND_H
