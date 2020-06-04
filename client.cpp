#include "client.h"
#include <exception>
#include <vector>
#include <iostream>
#include <string>
#include "common_command.h"
#include "common_factory_command.h"
#include "common_protocol.h"
#include "common_message.h"

Client::Client() {}

Client::~Client() {
	socket.shutdown(SHUT_RDWR);
}

void Client::connect(const char *host_name, const char *service) {
	socket.connect(host_name, service);
}

void Client::run() {
	Protocolable *protocolable;
	std::string line;
	Command *command;
	Message *msg;
	while (std::getline(std::cin, line)) {
		try {
			command = FactoryCommand::create(line);
    		Protocol::clientSend(socket, command);
			delete command;
			Protocol::clientReceive(socket, &protocolable);
			msg = static_cast<Message*>(protocolable);
			msg->print();
			if (msg->gameIsOver()) {
				delete msg;
				break;
			}
			delete msg;
		} catch (UnknownCommandException& e) {
			std::cout << unknown_msg << std::endl;
		}
	}
}
