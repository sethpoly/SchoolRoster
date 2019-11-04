#pragma once
//
// Created by Seth Polyniak on 10/4/19.
//

#ifndef softwareStudent_h
#define softwareStudent_h

#include "degree.h"
#include "student.h"

class softwareStudent : public Student {
public:
	Degree getDegreeProgram()   const;
	using Student::Student;     // inherit constructor


private:
	Degree degree = SOFTWARE;

};

#endif //C867_PA_SOFTWARESTUDENT_H
