#pragma once
#include <iostream>
#include <string>

using namespace std;

// class used to store the student data
class undergrad {
private: 
	int NTU_id = 0;
	char name[50] = {};
	int programming_marks = 0;
	int tech_n_maths_marks = 0;
	int profdev_marks = 0;
	int sys_ana_des_marks = 0;
	int essen_skills_marks = 0;
	double average_mark = 0.0;
	char grade[20] = {};

public:
	void getstudentdata();
	void calculate_grade();
	void showstudentdata() const;
	int retNTU_id() const;
};