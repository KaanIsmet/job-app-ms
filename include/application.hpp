#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <string>
#include <format>
#include <chrono>
#include <sstream>

using std::string;

enum Status {
	PENDING,
	REJECTED,
	ACCEPTED
};

class Application {
private:
	string companyName;
	string jobPosition;
	string salary;
	string contactInfo;
	Status status;
	string date;
public: 
	Application() : companyName("Unknown"), jobPosition("Unknown"), salary("Unknown"), contactInfo("Unknown"), status(PENDING) {}
	Application(string name, string position, string salary, string contactInfo, Status status) : 
		companyName(name),
		jobPosition(position),
		salary(salary),
		contactInfo(contactInfo),
		status(status) {
		
		auto now = std::chrono::system_clock::now();
		date = std::format("{:%m-%d-%Y}", std::chrono::floor<std::chrono::days>(now));
	}

	~Application() {}
	string getCompanyName() const;
	string getJobPosition() const;
	string getSalary() const;
	string getContactInfo() const;
	Status getStatus() const;
	string getDate() const;

	void setCompanyName(string name);
	void setJobPosition(string position);
	void setSalary(string salary);
	void setContactInfo(string info);
	void setStatus(Status status);
};
#endif
