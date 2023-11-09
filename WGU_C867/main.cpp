#include "roster.h"

int main()
{
	cout << "Scripting and Programming Applications C867, C++ , 003171047, Cody Pritchett\n" << "\n";//Fixed
	
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Cody,Pritchett,cprit36@wgu.edu,18,15,30,40,SOFTWARE"
	};

	const int numStudent = 5;
	roster roster;

	for (int i = 0; i < numStudent; i++) roster.parse(studentData[i]);
	cout << "Displaying All Students: " << std::endl;
	roster.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by Degree Program: " << DegreeProgramStrings[i] << std::endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Displaying students with invalid Emails: " << std::endl;
	roster.printInvalidEmail();
	cout << std::endl;

	cout << "Displaying Average Days in Course: " << std::endl;
	for (int i = 0; i < numStudent; i++)
	{
		roster.printAveragedays(roster.classRosterArray[i]->getStudentID());
	}
	cout << std::endl;

	cout << "Removing student with ID A5:" << std::endl;
	roster.removeStudentByID("A5");
	cout << std::endl;

	cout << "Removing Student with ID A5:" << std::endl;
	roster.removeStudentByID("A5");
	cout << std::endl;

	system("pause");
	return 0;

}