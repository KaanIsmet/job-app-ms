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

Command input() {
	std::string command;
	std::cin >> command;
	if (command == "/help") 
		return Command::HELP;
	else if (command == "/add") 
		return Command::ADD;
	else if (command == "/delete") 
		return Command::DELETE;
	else if (command == "/edit") 
		return Command::EDIT;
	else if (command == "/exit") 
		return Command::EXIT;
	else if (command == "/list")
		return Command::LIST;
	else 
		return Command::INVALID;
}
			
