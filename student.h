#pragma once
//
// Created by Seth Polyniak on 10/4/19.
//

#ifndef student_h
#define student_h
#include <string>
#include "degree.h"
using namespace std;


class Student {
public:
	// Constructor
	Student(string studentID, string firstName, string lastName,
		string email, int age, int daysToComplete[3], Degree degreeType);

	// Destructor
	~Student();

	// Setters
	void    setStudentID(string studentID);
	void    setFirstName(string firstName);
	void    setLastName(string lastName);
	void    setEmail(string email);
	void    setAge(int age);
	void    setDaysToComplete(int daysToComplete[]);
	void    setDegreeType(Degree degreeType);

	// Getters
	string     getStudentID()      const;
	string  getFirstName()      const;
	string  getLastName()       const;
	string  getEmail()          const;
	int     getAge()            const;
	int* getDaysToComplete();

	// Will be overrided in the Student subclasses
	virtual Degree getDegreeProgram();

	// Print info about student
	virtual void print();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int    age;
	Degree degreeType;
	int    daysToComplete[3];
};
#endif
