#include "student.h"

student::student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

student::student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram) 
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;

}

student::~student() {}

string student::getStudentID() { return this->studentID; }
string student::getFirstName() { return this->firstName; }
string student::getLastName() { return this->lastName; }
string student::getEmailAddress() { return this->emailAddress; }
int student::getAge() { return this->age; }
int* student::getDays() { return this->days; }
DegreeProgram student::getDegreeProgram() { return this->degreeProgram; }


void student::setStudentID(string studentID) { this->studentID = studentID; }
void student::setFirstName(string firstName) { this->firstName = firstName; }
void student::setLastName(string lastName) { this->lastName = lastName; }
void student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void student::setage(int age) { this->age = age; }
void student::setDays(int days[])
{
	for (int i = 0; i < dayArraySize; i++) this->days[i] = days[i];
}
void student::setDegreeProgram(DegreeProgram DP) { this->degreeProgram = DP; }


void student::printHeader() 
{
	cout << "Output format: StudentID|First Name|Last Name|Email Address|Age|Days in Course|Degree Program\n";
}

void student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << DegreeProgramStrings[this->getDegreeProgram()] << '\n';
}