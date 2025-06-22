# include "StudentDatabase.h"

bool StudentDatabase::openFile(fstream& file, ios_base::openmode mode) {
    file.open(filename, mode);
    return file.is_open();
}

// Create a new student record
bool StudentDatabase::createRecord(const undergrad& student) {
    try {
        ofstream oFile(filename, ios::binary | ios::app);
        if (!oFile) {
            throw runtime_error("Unable to open file for writing");
        }
        oFile.write(reinterpret_cast<const char*>(&student), sizeof(undergrad));
        oFile.close();
        cout << "\nStudent record has been created successfully";
        return true;
    }
    catch (const exception& e) {
        cout << "Error creating record: " << e.what() << endl;
        return false;
    }
}

// Dislay all student records
void StudentDatabase::displayAllRecords() {
    try {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            throw runtime_error("Unable to open file for reading");
        }

        cout << "\n\n\t\tDISPLAYING ALL RECORDS\n";
        cout << "\n====================================\n";

        undergrad student;
        int count = 0;
        while (inFile.read(reinterpret_cast<char*>(&student), sizeof(undergrad))) {
            student.showstudentdata();
            cout << "\n====================================\n";
            count++;
        }

        if (count == 0) {
            cout << "No records found.\n";
        }

        inFile.close();
    }
    catch (const exception& e) {
        cout << "Error displaying records: " << e.what() << endl;
    }
}

// Displaying a specific student record 
bool StudentDatabase::displayRecord(int studentId) {
    try {
        ifstream iFile(filename, ios::binary);
        if (!iFile) {
            throw runtime_error("Unable to open file for reading");
        }

        undergrad student;
        bool found = false;

        while (iFile.read(reinterpret_cast<char*>(&student), sizeof(undergrad))) {
            if (student.retNTU_id() == studentId) {
                student.showstudentdata();
                found = true;
                break;
            }
        }

        iFile.close();
        if (!found) {
            cout << "\nRecord not found for NTU ID: N" << studentId << endl;
        }
        return found;
    }
    catch (const exception& e) {
        cout << "Error searching record: " << e.what() << endl;
        return false;
    }
}

// Modify a specific student record
bool StudentDatabase::modifyRecord(int studentId) {
    try {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            throw runtime_error("Unable to open file for modification");
        }

        undergrad student;
        bool found = false;

        while (file.read(reinterpret_cast<char*>(&student), sizeof(undergrad))) {
            if (student.retNTU_id() == studentId) {
                cout << "\nCurrent Record Details:\n";
                student.showstudentdata();
                cout << "\nEnter new details:\n";
                student.getstudentdata();

                file.seekp(-static_cast<int>(sizeof(undergrad)), ios::cur);
                file.write(reinterpret_cast<char*>(&student), sizeof(undergrad));
                found = true;
                cout << "\nRecord updated successfully";
                break;
            }
        }

        file.close();
        if (!found) {
            cout << "\nRecord not found for NTU ID: N" << studentId << endl;
        }
        return found;
    }
    catch (const exception& e) {
        cout << "Error modifying record: " << e.what() << endl;
        return false;
    }
}

// Delete a specific student record
bool StudentDatabase::deleteRecord(int studentId) {
    try {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            throw runtime_error("Unable to open source file");
        }

        ofstream outFile(temp_filename, ios::binary);
        if (!outFile) {
            inFile.close();
            throw runtime_error("Unable to create temporary file");
        }

        undergrad student;
        bool found = false;

        while (inFile.read(reinterpret_cast<char*>(&student), sizeof(undergrad))) {
            if (student.retNTU_id() != studentId) {
                outFile.write(reinterpret_cast<char*>(&student), sizeof(undergrad));
            }
            else {
                found = true;
            }
        }

        inFile.close();
        outFile.close();

        if (found) {
            if (remove(filename.c_str()) != 0) {
                throw runtime_error("Error deleting original file");
            }

            if (rename(temp_filename.c_str(), filename.c_str()) != 0) {
                throw runtime_error("Error renaming temporary file");
            }
            cout << "\nRecord deleted successfully";
        }
        else {
			remove(temp_filename.c_str()); // Clean up temporary file if not found
            cout << "\nRecord not found for NTU ID: N" << studentId << endl;
        }

        return found;
    }
    catch (const exception& e) {
        cout << "Error deleting record: " << e.what() << endl;
        return false;
    }
}