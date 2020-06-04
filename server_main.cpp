#include <stdlib.h>
#include <iostream>
#include <exception>
#include "server.h"

int main(int argc, char const *argv[]) {
	try {
		if (argc != 3) {
			std::cerr << args_inval_msg << std::endl;
			return EXIT_FAILURE;	
		}
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
