#ifndef RR_FILE_READER_H
#define RR_FILE_READER_H

#include <string>
#include <vector>

class RRFileReader {
private:
	std::vector<std::string> file_lines;
	unsigned int actual_line;
public:
	/*
		Realiza la apertura del archivo a leer y llena el vector file_lines
		con su contenido.
		Lanza std::exception() en caso de error.
	*/
	explicit RRFileReader(const char* file_name);
	~RRFileReader();
	/*
		Devuelve una línea leída del archivo en forma de Round Robin,
		cada vez que es llamado.
	*/
	std::string getline();
};

#endif // RR_FILE_READER_H
