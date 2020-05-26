#ifndef COMMAND_H
#define COMMAND_H

#include "common_protocolable.h"
#include "common_types_command.h"

class Command : public Protocolable {
public:
	Command();
	virtual ~Command();
};

#endif // COMMAND_H
