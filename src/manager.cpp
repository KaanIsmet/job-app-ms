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

void Manager::deleteJob(int jobId) {
	//create a temp file to delete the app and copy the contents
	//have the temp file close
	//rename the temp file to original file
	applications.erase(jobId);
	std::ofstream temp("temp.csv");
	std::stringstream ss;
	ss << headers;
	ss << std::endl;
	for (const auto& entry : applications) {
		auto app = entry.second;
		ss << app.getCompanyName() << ", " 
			<< app.getJobPosition() << ", " 
			<< app.getSalary() << ", " 
			<< app.getContactInfo() << ", "
			<< app.getStatus() << ", "
			<< app.getDate() << std::endl;
	}
	temp << ss.str();
	temp.close();
	std::filesystem::rename("temp.csv", fileName);

}

void Manager::editJob(int jobId, Application app) {
	auto it = applications.find(jobId);
	if (it != applications.end()) {
		it->second = app;
		std::ofstream temp("temp.csv");
		std::stringstream ss;
		ss << headers;
		ss << std::endl;
		for (const auto& entry : applications) {
			auto app = entry.second;
			ss << app.getCompanyName() << ", " 
				<< app.getJobPosition() << ", " 
				<< app.getSalary() << ", " 
				<< app.getContactInfo() << ", "
				<< app.getStatus() << ", "
				<< app.getDate() << std::endl;
		}
		temp << ss.str();
		temp.close();
		std::filesystem::rename("temp.csv", fileName);
	}
}
