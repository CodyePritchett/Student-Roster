#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


class student 
{	
	public:
		const static int dayArraySize = 3;
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int days[dayArraySize];
		DegreeProgram degreeProgram;
	public:
		student();
		student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
		~student();

		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDays();
		DegreeProgram getDegreeProgram();

		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setage(int age);
		void setDays(int days[]);
		void setDegreeProgram(DegreeProgram dp);

		static void printHeader();

		void print();
};