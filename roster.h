#pragma once
//
// Created by Seth Polyniak on 10/4/19.
//

#ifndef roster_h
#define roster_h
#include <string>
#include <vector>
#include "degree.h"
using namespace std;

// Number of students in roster
int numOfStudents = 5;

// Number of attributes per student
const int numOfAttributes = 8;

const string studentData[5] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Seth,Polyniak,spolyn1@wgu.com,21,20,30,25,SOFTWARE" };


class roster {
public:
	// Default constructor
	roster();

	~roster();

	// Creates all the students from studentData table
	void inititalizeStudents();

	// Adds each student to the roster
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
		Degree degree);

	// removes students from the roster by student ID
	void remove(string studentID);

	void printAll();

	void printDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(int degreeProgram);

	string enumIntToString(int degreeProgram);

	//vector<Student*> getClassRosterArray();

	Student* classRosterArray[6] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};


	

#endif //C867_PA_ROSTER_H
