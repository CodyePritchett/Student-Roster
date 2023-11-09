#pragma once
#include "student.h"
class roster
{
	public:
		int lastIndex = -1;
		const static int numStudent = 7;
		student* classRosterArray[numStudent];

	public:
		void parse(string row);
		void add(string studentID,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int days1,
			int days2,
			int days3,
			DegreeProgram DP);
		void printAll();
		void printByDegreeProgram(DegreeProgram DP);
		void printInvalidEmail();
		void printAveragedays(string studentID);
		void removeStudentByID(string studentID);
		~roster();
};