#include "roster.h"
void roster::parse(string studentData)
{
	DegreeProgram DP = SECURITY;
	if (studentData.back() == 'K') DP = NETWORK;
	else if (studentData.back() == 'E') DP = SOFTWARE;

	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EM = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int AG = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DA1 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DA2 = stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int DA3 = stoi(studentData.substr(lhs, rhs - lhs));

	add(sID, FN, LN, EM, AG, DA1, DA2, DA3, DP);
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	
	int parr[3] = { days1,days2,days3 };
	classRosterArray[++lastIndex] = new student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
}


void roster::printAll()
{
	student::printHeader();
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		classRosterArray[i]->print();// Fixed
	}
}

void roster::printByDegreeProgram(DegreeProgram DP)
{
	student::printHeader();
	for (int i = 0; i <= roster::lastIndex; i++) {
		if (roster::classRosterArray[i]->getDegreeProgram() == DP) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void roster::printInvalidEmail()
{
	bool any = false;
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		string EM = (classRosterArray[i]->getEmailAddress());
		if (EM.find('@') == string::npos || (EM.find('.') == string::npos || EM.find(' ') != string::npos))
		{
			any = true;
			cout << EM << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}


void roster::printAveragedays(string studentID)
{
	for (int i = 0; i <= roster::lastIndex; i++) 
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDays()[0] +
				classRosterArray[i]->getDays()[1] +
				classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
		}
	}
}

void roster::removeStudentByID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudent - 1)
			{
				student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudent - 1];
				classRosterArray[numStudent - 1] = temp;
			}
			roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}


roster::~roster()
{
	cout << "DESTRUCTOR ACTIVATED!!" << std::endl << std::endl;
	for (int i = 0; i < numStudent; i++)
	{
		cout << "Deleteing student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}