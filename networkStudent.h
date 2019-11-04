#pragma once
//  Created by Seth Polyniak on 10/4/19.
//  Copyright © 2019 Seth Polyniak. All rights reserved.
//

#ifndef networkStudent_h
#define networkStudent_h

#include "degree.h"
#include "student.h"

class networkStudent : public Student {
public:
	Degree getDegreeProgram()   const;
	using Student::Student;     // inherit constructor

private:
	Degree degree = NETWORK;

};


#endif /* networkStudent_h */
