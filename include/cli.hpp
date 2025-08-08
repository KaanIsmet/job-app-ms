#ifndef CLI_HPP
#define	CLI_HPP

#include <string>
#include <vector>
enum Command {
	HELP,
	ADD,
	EDIT,
	DELETE,
	LIST,
	EXIT,
	INVALID
};


void print();
void help();
Command input();
#endif
