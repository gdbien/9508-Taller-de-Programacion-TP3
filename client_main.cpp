#include <iostream>
#include <exception>
#include "client.h"

int main(int argc, char const *argv[]) {
	Client client;
	try {
		if (argc != 3) {
			std::cout << args_inval_msg << std::endl;
			return EXIT_SUCCESS;	
		}
		client.connect(argv[1], argv[2]);
		client.run();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_SUCCESS;
	} catch (...) {
		std::cerr << "Error: Unknown Exceptions" << std::endl;
		return EXIT_SUCCESS;
	}
	return EXIT_SUCCESS;
}
