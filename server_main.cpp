#include <stdlib.h>
#include <iostream>
#include <exception>
#include "server.h"

int main(int argc, char const *argv[]) {
	try {
		if (argc != 3) {
			std::cerr << "Error: argumentos invalidos." << std::endl;
			return EXIT_FAILURE;	
		} // Falta chequear los otros 2 errores, podría crear una clase
		  // tipo CheckInput que haga todos los chequeos
		Server server(argv[2]);
		server.bindAndListen(argv[1]);
		server.run();	
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	} catch (...) {
		std::cerr << "Error: Unknown Exceptions" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
