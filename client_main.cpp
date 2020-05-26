#include <stdlib.h>
#include <iostream>
#include <exception>
#include "client.h"

int main(int argc, char const *argv[]) {
	Client client;
	try {
		if (argc != 3) {
			std::cerr << "Error: argumentos invalidos." << std::endl;
			return EXIT_FAILURE;	
		}
		client.connect(argv[1], argv[2]);
		client.run();
		client.shutdown();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		client.shutdown();
		return EXIT_FAILURE;
	} catch (...) {
		std::cerr << "Error: Unknown Exceptions" << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
