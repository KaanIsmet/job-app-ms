#include "../include/manager.hpp"
#include <sstream>
using std::string;


void Manager::addJob(Application app) {
	applications.insert({nextId, app});
	nextId++;
	std::stringstream ss;
	string status;
	if (app.getStatus() == Status::PENDING)
		status = "Pending";
	else if (app.getStatus() == Status::REJECTED)
		status = "Rejected";
	else if (app.getStatus() == Status::ACCEPTED)
		status = "Accepted";
	else 
		status = "Unknown";

	std::ofstream file(fileName, std::ios_base::app);
	ss << std::endl;
	ss << app.getCompanyName() << ", " 
	   << app.getJobPosition() << ", "
	   << app.getSalary() << ", "
	   << app.getContactInfo() << ", "
	   << status << ", "
	   <<app.getDate() << std::endl;
	file << ss.str();
	file.close();
}	

void Manager::readList() const {

	std::ifstream file(fileName);
	string line;
	while (std::getline(file, line)) {
		std::cout << line << std::endl;
	}
	file.close();
}

void Manager::deleteJob(Application app) const {
	//create a temp file to delete the line and copy the contents
	//have the original file copy the temp file
	//delete the temp file
	string line;
	std::ifstream file(fileName);
	std::ofstream temp("temp.csv");

	while (std::getline(file, line)) {
		
	}

	file.close();
	temp.close();

}

void Manager::editJob(Application app) const {}
