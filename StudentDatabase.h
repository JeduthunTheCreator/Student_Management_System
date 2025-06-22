#pragma once
#include "undergrad.h"
#include <fstream>
#include <string>

class StudentDatabase {
private:
	// File handling variables
	const string filename = "undergrad.dat";
	const string temp_filename = "Temp.dat";

	// File stream for reading and writing records
	bool openFile(fstream& file, ios_base::openmode mode);

public:
	// Constructor and destructor
	bool createRecord(const undergrad& student);
	void displayAllRecords();
	bool displayRecord(int studentId);
	bool modifyRecord(int studentId);
	bool deleteRecord(int studentId);
};