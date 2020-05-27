#include "client.h"
#include <exception>
#include <vector>
#include "common_command.h"
#include "common_factory_command.h"
#include "common_protocol.h"
#include "common_message.h"

Client::Client() {}

Client::~Client() {}

void Client::connect(const char *host_name, const char *service) {
	this->socket.connect(host_name, service);
}

void Client::shutdown() {
	this->socket.shutdown(SHUT_RDWR);
}

void Client::run() {
	/*
		Aca tendría que tener un while (true) con un try catch.
		Lo que se hace adentro es leer de la entrada, y pasarle lo leido a
		FactoryCommand::create(input) el cual lanza excepción si no existe el
		commando (esto incluye numerico invalido), y ahí imprimo el mensaje de
		error de comando inválido.
		El "RENDIRSE" esta ahí de prueba.
	*/
	Protocolable *prtble;
	Command *command = FactoryCommand::create("345");
	Protocol::clientSend(this->socket, command);
	delete(command);
	Protocol::clientReceive(this->socket, &prtble);
	Message *msg = static_cast<Message*>(prtble);
	msg->print();
	delete msg;
}
