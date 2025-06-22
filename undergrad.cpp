# include "undergrad.h"
#include <cstring>

void undergrad::getstudentdata()
{
    const int MAX_MARKS = 100;
    const int MIN_MARKS = 0;

    // Input validation for NTU ID
    while (true) {
        cout << "\nEnter student's NTU ID: N";
        if (cin >> NTU_id && NTU_id > 0) {
            break;
        }
        cout << "Invalid NTU ID. Please enter a positive number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Input validation for name 
    cout << "\n\nEnter student name: ";
    cin.ignore();
    cin.getline(name, 50);
    while (strlen(name) == 0) {
        cout << "Name cannot be empty. Please enter a valid name: ";
        cin.getline(name, 50);
    }

    cout << "\nAll marks should be out of 100";

    // Function to handle mark input 
    auto getValidMark = [&](const string& module_name) {
        int marks;
        while (true) {
            cout << "\nEnter marks in " << module_name << " Module: ";
            if (cin >> marks && marks >= MIN_MARKS && marks <= MAX_MARKS) {
                return marks;
            }
            cout << "Invalid marks. Please enter a number between " << MIN_MARKS << " and " << MAX_MARKS << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        };

    programming_marks = getValidMark("SOFT10101 (Computer Programming)");
    tech_n_maths_marks = getValidMark("ITEC10261 (Computer Technology & Maths)");
    profdev_marks = getValidMark("ISYS10401 (Prof Development for Industry)");
    sys_ana_des_marks = getValidMark("ISYS10242 (System Analysis & Design)");
    essen_skills_marks = getValidMark("ISYS10301 (Essential Skills)");

    calculate_grade();
}

void undergrad::calculate_grade()
{
    average_mark = (programming_marks + tech_n_maths_marks + profdev_marks + sys_ana_des_marks + essen_skills_marks) / 5.0;
    if (average_mark >= 93)
        strcpy(grade, "Exceptional 1st");
    else if (average_mark >= 85)
        strcpy(grade, "High 1st");
    else if (average_mark >= 78)
        strcpy(grade, "Mid 1st");
    else if (average_mark >= 70)
        strcpy(grade, "Low 1st");
    else if (average_mark >= 67)
        strcpy(grade, "High 2.1");
    else if (average_mark >= 64)
        strcpy(grade, "Mid 2.1");
    else if (average_mark >= 60)
        strcpy(grade, "Low 2.1");
    else if (average_mark >= 57)
        strcpy(grade, "High 2.2");
    else if (average_mark >= 54)
        strcpy(grade, "Mid 2.2");
    else if (average_mark >= 50)
        strcpy(grade, "Low 2.2");
    else if (average_mark >= 47)
        strcpy(grade, "High 3rd");
    else if (average_mark >= 44)
        strcpy(grade, "Mid 3rd");
    else if (average_mark >= 40)
        strcpy(grade, "Low 3rd");
    else if (average_mark >= 35)
        strcpy(grade, "Marginal Fail");
    else if (average_mark >= 30)
        strcpy(grade, "Mid Fail");
    else if (average_mark >= 1)
        strcpy(grade, "Low Fail");
    else
        strcpy(grade, "Zero");
}
void undergrad::showstudentdata() const
{
    cout << "\nNTU ID of student : N" << NTU_id;
    cout << "\nName of student : " << name;
    cout << "\nSOFT10101 (Computer Programming) Module : " << programming_marks;
    cout << "\nITEC10261 (Computer Technology & Maths) Module : " << tech_n_maths_marks;
    cout << "\nISYS10401 (Prof Development for Industry) Module : " << profdev_marks;
    cout << "\nISYS10242 (System Analysis & Design) Module : " << sys_ana_des_marks;
    cout << "\nISYS10301 (Essential Skills) Module :" << essen_skills_marks;
    cout << "\nThe average Mark of all the modules :" << average_mark;
    cout << "\nGrade of student is :" << grade;
}

int  undergrad::retNTU_id() const
{
    return NTU_id;
}