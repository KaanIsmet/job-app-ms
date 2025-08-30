#include <iostream>
#include <cstdlib>
#include "../include/cli.hpp"
#include "../include/application.hpp"
#include "../include/manager.hpp"

int main() {
	std::string name, position, salary, contact, fileName = "sample.csv";
	Status status = Status::PENDING;
	print();

	Manager manager(fileName);	
	while (true) {
		Command c = input();
		//use if - else statements for the prompts	
		if (c == Command::ADD) {
			std::cout << "Enter Company's name: " << std::endl;
			std::cin >> name;
			std::cout << "Enter Job position: " << std::endl;
			std::cin >> position;
			std::cout << "Enter Salary: " << std::endl;
			std::cin >> salary;
			std::cout << "Enter Contact info: " << std::endl;
			std::cin >> contact;
			Application app(name, position, salary, contact, status);
			manager.addJob(app);

		}
		else if (c == Command::EDIT) {

		}

		else if (c == Command::DELETE) {
			int id;
			std::cout << "Enter company's number to delete" << std::endl;
			std::cin >> id;
			manager.deleteJob(id);
			std::cout << "Company: " << id << " has been deleted.\n";
		}

		else if (c == Command::LIST) {
			manager.readList();
		}

		else if (c == Command::HELP) {
			help();
		}

		else if (c == Command::EXIT) {
			break;
		}
		else if (c == Command::INVALID) {
			std::cerr << "Invalid command." << std::endl;
			help();
		}
		else {
			std::cerr << "Unknown error." << std::endl;
		}
	}
	return 0;
}
