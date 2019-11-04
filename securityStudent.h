#pragma once
//
// Created by Seth Polyniak on 10/4/19.
//

#ifndef securityStudent_h
#define securityStudent_h

#include "degree.h"
#include "student.h"

class securityStudent : public Student {
public:
	Degree getDegreeProgram()   const;
	using Student::Student;     // inherit constructor

private:
	Degree degree = SECURITY;

};

#endif //C867_PA_SECURITYSTUDENT_H
