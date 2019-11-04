//
// Created by Seth Polyniak on 10/4/19.
//

#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

#include "roster.h"
#include "degree.h"
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

const string courseTitle = "C867: Scripting and Programming - Applications";
const string programmingLanguage = "C++";
const string studentID = "#001261470";
const string myName = "Seth Polyniak";

// Constructor init to create the students
roster::roster() {
	//this->inititalizeStudents();
}

roster::~roster() { cout << "Destructor is called and roster is released from memory." << endl; }

// Prints all students
void roster::printAll() {
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

// Adds a student to the roster
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {


	// Create student pointer for new student
	//Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);

	// Get daysToComplete array from the 3 numbers listed
	int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	// Loop through size of classRoster and check if the element is empty
	// If so then create student based off degree
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {

			switch (degree) {
				// Security
			case 0:
				classRosterArray[i] = new securityStudent(studentID, firstName, lastName, 
														  emailAddress, age, daysToComplete, degree);
				break;

				// Network
			case 1:
				classRosterArray[i] = new networkStudent(studentID, firstName, lastName,
					emailAddress, age, daysToComplete, degree);
				break;

				// Software
			case 2:
				classRosterArray[i] = new softwareStudent(studentID, firstName, lastName,
					emailAddress, age, daysToComplete, degree);
				break;
			}

			// Break from for loop when student is created and assigned to roster
			break;

			// Create type of student object based off degree
			/*if (degree == NETWORK) {
				networkStudent netStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);

				newStudent = &netStudent;
			}
			else if (degree == SOFTWARE) {
				softwareStudent softStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);

				newStudent = &softStudent;
			}
			else if (degree == SECURITY) {
				securityStudent securStudent(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);

				newStudent = &securStudent;
			}*/
		}
}

	// Append to classRosterArray
	//classRosterArray.push_back(new Student(*newStudent));
}

// Will remove the element in classRoster array by studentID
void roster::remove(string studentID) {

	bool idExists = false;  // Determines if a student with specified id exists

	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			cout << classRosterArray[i]->getStudentID() << " was removed from roster." << endl;
			//classRosterArray.erase(classRosterArray.begin() + i);

			// Update number of students
			//numOfStudents--;

			// Set that student to a nullptr to simulate him/her being removed from the roster
			classRosterArray[i] = nullptr;

			idExists = true;
			break;
		}
	}

	// If no id was found of specified student, print out error message
	if (!idExists) {
		cout << "No student with matching ID: " << studentID << " was found." << endl;
	}
}

// Prints a student’s average number of days in the three courses
void roster::printDaysInCourse(string studentID) {

	int sum = 0;            // The sum of 3 courses
	double average = 0;     // The average of 3 courses

	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {

			// Adds all course times
			sum = classRosterArray[i]->getDaysToComplete()[0] + classRosterArray[i]->getDaysToComplete()[1] + classRosterArray[i]->getDaysToComplete()[2];

			average = sum / 3.0;

			break;
		}
	}
	cout << "The average number of days in the 3 courses for student " << studentID << " is " << average << endl;
}

// WIll print out all emails of students and declare if they are valid or invalid
void roster::printInvalidEmails() {

	string atSymbol = "@";
	string periodSymbol = ".";
	string spaceSymbol = " ";

	cout << "Invalid emails: " << endl;
	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmail();

			if (email.find(atSymbol) != string::npos && email.find(periodSymbol) != string::npos && email.find(spaceSymbol) == string::npos) {
				//cout << "VALID: " << email << " is a valid email address." << endl;
			}
			else {
				cout << email << endl;
			}
		}
	}
}

// Prints out the student information based on degree type
void roster::printByDegreeProgram(int degreeProgram) {

	cout << enumIntToString(degreeProgram) << ": Student information" << endl;

	for (int i = 0; i < numOfStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
}

// Converts degree enum to a string
string roster::enumIntToString(int degreeProgram) {
	string degreeString;

	switch (degreeProgram) {
	case 0:
		degreeString = "Security";
		break;

	case 1:
		degreeString = "Network";
		break;

	case 2:
		degreeString = "Software";
		break;

	default:
		break;
	}
	return degreeString;
}

// Main method that runs and outputs the required information
int main() {
	cout << courseTitle << endl
		<< programmingLanguage << endl
		<< studentID << endl
		<< myName << endl << endl;

	// Init the roster object
	roster *classRoster = new roster();

	// Using the studentData table array, loop through each line (student)
	for (int i = 0; i < numOfStudents; i++) {
		stringstream studentStream(studentData[i]);
		
		// Vector that is used to hold each line of student data
		vector<string> studentLines;

		// Delimeter used to find separation of attributes
		char delimeter = ',';

		while (studentStream.good()) {
			string attribute;		// The next attribute of the student
			getline(studentStream, attribute, delimeter);

			// Append the attribute to studentLines vector
			studentLines.push_back(attribute);
		}

		// Must convert the degree from string to of type: Degree 
		string stringDegree = studentLines.at(8);
		Degree convertedDegree;

		if (stringDegree == "NETWORK") {
			convertedDegree = NETWORK;
		}
		else if (stringDegree == "SECURITY") {
			convertedDegree = SECURITY;
		}
		else if (stringDegree == "SOFTWARE") {
			convertedDegree = SOFTWARE;
		}

		// append to roster using add() function
		classRoster->add(studentLines.at(0), studentLines.at(1), studentLines.at(2),
			studentLines.at(3), stoi(studentLines.at(4)), stoi(studentLines.at(5)),
			stoi(studentLines.at(6)), stoi(studentLines.at(7)), convertedDegree);
	}
	

	cout << "// printAll() function" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "// printInvalidEmails function" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	cout << "// Loop through classRosterArray & print average days in course" << endl;
	for (int i = 0; i < numOfStudents; i++) {
		classRoster->printDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "// printByDegreeProgram function" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "// remove() function" << endl;
	classRoster->remove("A3");
	classRoster->remove("A3");
	cout << endl;

	// Call the destructor
	delete classRoster;

	return 0;
}
