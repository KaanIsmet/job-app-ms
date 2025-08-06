#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <application.hpp>
#include <filesystem>

using std::string;

class Manager {
private:
	string fileName;
	
public:
	Manager() : fileName("unknown.txt") {}
	Manager(string fileName) : fileName(fileName) {
		std::string headers = "Company, Position, Salary, Contact, Status, Date";
		std::stringstream ss;
		ss << headers;

		if (std::filesystem::exists(fileName)) {
			std::cout << "File exists" << std::endl;
		}
		else {
			std::cout << "Creating file..." << std::endl;
			std::ofstream file(fileName);
			file << ss.str();
			file.close();
		}
	}
	~Manager() {}
	void addJob(Application app) const;
	void readList() const;
	void editJob(Application app) const;
	void deleteJob(Application app) const;
};
#endif
