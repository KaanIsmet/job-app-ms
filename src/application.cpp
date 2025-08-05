#include "../include/application.hpp"

string Application::getCompanyName() const { return companyName; }
string Application::getJobPosition() const { return jobPosition; }
string Application::getSalary() const { return salary; }
string Application::getContactInfo() const { return contactInfo; }
Status Application::getStatus() const { return status; }
string Application::getDate() const { return date; }
void Application::setCompanyName(string companyName) { this->companyName = companyName; }
void Application::setJobPosition(string jobPostion) { this->jobPosition = jobPosition; }
void Application::setSalary(string salary) { this->salary = salary; }
void Application::setContactInfo(string contactInfo) { this->contactInfo = contactInfo; }
void Application::setStatus(Status status) { this->status = status; }
