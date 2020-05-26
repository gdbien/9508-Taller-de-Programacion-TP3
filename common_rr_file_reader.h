#ifndef RR_FILE_READER_H
#define RR_FILE_READER_H

#include <fstream>

class RRFileReader {
private:
	std::ifstream input;
public:
	RRFileReader(const char* file_name);
	~RRFileReader();
	std::string getline();
};

#endif // RR_FILE_READER_H

