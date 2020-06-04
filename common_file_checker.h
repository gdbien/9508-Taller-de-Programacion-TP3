#ifndef FILE_CHECKER_H
#define FILE_CHECKER_H

#define F_CHK_SUCCESS 0
#define F_CHK_INVL_PATRN -1
#define F_CHK_INVL_RANGE -2

class FileChecker {
public:
	FileChecker();
	~FileChecker();
	static int isGood(const char *file_name, const unsigned int &digit_count);
};

#endif // FILE_CHECKER_H
