//
// Created by Seth Polyniak on 10/4/19.
//

#include "student.h"
#include "degree.h"

#include "iostream"
using namespace std;

// Default Constructor for each Student object
Student::Student(string studentID, string firstName, string lastName,
	string email, int age, int daysToComplete[3], Degree degreeType) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysToComplete(daysToComplete);
	setDegreeType(degreeType);
}
	// Destructor definition
	Student::~Student() {
	}

// Define the functions

// Setters
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
	return;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}
void Student::setEmail(string email) {
	this->email = email;
	return;
}
void Student::setAge(int age) {
	this->age = age;
	return;
}
void Student::setDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < 3; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	return;
}
void Student::setDegreeType(Degree degreeType) {
	this->degreeType = degreeType;
	return;
}

// Getters
string Student::getStudentID() const {
	return this->studentID;
}

string Student::getFirstName() const {
	return this->firstName;
}

string Student::getLastName() const {
	return this->lastName;
}

string Student::getEmail() const {
	return this->email;
}

int Student::getAge() const {
	return this->age;
}

int* Student::getDaysToComplete() {
	return daysToComplete;
}

// How can you have an empty function when it has a return type of Degree?
Degree Student::getDegreeProgram() {
	return degreeType;
}

void Student::print() {

	string degreeString;

	// Convert degreeProgram to string
	switch (getDegreeProgram()) {
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

	cout << "Student ID: " << getStudentID() << "   "
		<< "First name: " << getFirstName() << "   "
		<< "Last name: " << getLastName() << "   "
		<< "Age: " << getAge() << "   "
		<< "Days in course: " << "{" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}    "
		<< "Degree Program: " << degreeString << "   " << endl;
}


