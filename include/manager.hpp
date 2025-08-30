#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <application.hpp>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include "status.hpp"
using std::string;

class Manager {
private:
	string fileName;
	string headers = "Company, Position, Salary, Contact, Status, Date";
	std::unordered_map<int,Application> applications;
	int nextId = 1;
public:
	Manager() : fileName("unknown.txt") {}
	Manager(string fileName) : fileName(fileName) {
		std::stringstream ss;
		ss << headers;
		
		if (std::filesystem::exists(fileName)) {
			std::cout << "File exists" << std::endl;
			std::ifstream file(fileName);
			string line;
			int numLines = 0;
			//map the applications
			while (std::getline(file, line)) {
				if (numLines == 0) {
					numLines++;
					continue;
				}
				auto data = split(line, ',');
				Application app(data);
				applications.insert({nextId, app});
				nextId++;
			}
		}
		else {
			std::cout << "Creating file..." << std::endl;
			std::ofstream file(fileName);
			file << ss.str();
			file.close();
		}
	}
	~Manager() {}
	void addJob(Application app);
	void readList() const;
	void editJob(int jobId, Application app);
	void deleteJob(int jobId);

	string trim(const string& str) const {
		size_t start = str.find_first_not_of(" \t\n\r\f\v");
		if (start == std::string::npos) return "";

		size_t end = str.find_last_not_of(" \t\n\r\f\v");
		return str.substr(start, end - start + 1);
	}

	std::vector<string> split(const string& str, char delimeter) const {
		std::vector<string> tokens;
		std::stringstream ss(str);
		string token;
		while (std::getline(ss, token, delimeter)) {
			token = trim(token);
			tokens.push_back(token);
		}
		return tokens;
	}

};
#endif
