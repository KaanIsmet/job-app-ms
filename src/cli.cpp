#include <iostream>
#include "../include/cli.hpp"


void print() {
	std::cout << "Job applications management system\n"
		  << "===================================\n"
		  << "For help, type /help\n";
}

void help() {
	std::cout << "Command lists\n"
		  << "============="
		  << "/show\n"
		  << "/append\n"
		  << "/edit\n"
		  << "/delete\n"
		  << "/exit\n";
}
