#include "Menu.h"


void Menu::displayHeader() {
	system("cls");
	cout << "\n\n\t\t====================================";
	cout << "\n\t\t  STUDENT MANAGEMENT SYSTEM";
	cout << "\n\t\t===================================="; 
}


void Menu::displayMenu() {
    cout << "\n\n\t\t\tMAIN MENU";
    cout << "\n\t\t______________________________________";
    cout << "\n\n\t\t1. Create Student Record";
    cout << "\n\t\t2. Search Student Record";
    cout << "\n\t\t3. Display All Records";
    cout << "\n\t\t4. Delete Student Record";
    cout << "\n\t\t5. Modify Student Record";
    cout << "\n\t\t6. Exit";
    cout << "\n\t\t______________________________________";
    cout << "\n\n\t\tEnter Your Choice (1-6): ";
}

void Menu::processChoice(char choice) {
    int studentId;
    system("cls");

    switch(choice) {
        case '1': {
            cout << "\n\n\t\tCREATE STUDENT RECORD\n";
            undergrad student;
            student.getstudentdata();
            db.createRecord(student);
            break;
        }
        case '2': {
            cout << "\n\n\t\tSEARCH STUDENT RECORD\n";
            cout << "\n\tEnter Student NTU ID: N";
            cin >> studentId;
            db.displayRecord(studentId);
            break;
        }
        case '3': {
            cout << "\n\n\t\tALL STUDENT RECORDS\n";
            db.displayAllRecords();
            break;
        }
        case '4': {
            cout << "\n\n\t\tDELETE STUDENT RECORD\n";
            cout << "\n\tEnter Student NTU ID: N";
            cin >> studentId;
            db.deleteRecord(studentId);
            break;
        }
        case '5': {
            cout << "\n\n\t\tMODIFY STUDENT RECORD\n";
            cout << "\n\tEnter Student NTU ID: N";
            cin >> studentId;
            db.modifyRecord(studentId);
            break;
        }
        case '6': {
            cout << "\n\n\t\tThank you for using the system!\n";
            cout << "\t\tPress any key to exit...";
            cin.ignore();
            cin.get();
            exit(0);
        }
        default: {
            cout << "\n\n\t\tInvalid Choice! Please try again...";
            break;
        }
    }
    cout << "\n\n\t\tPress any key to continue...";
    cin.ignore();
    cin.get();
}

void Menu::run() {
    char choice;
    do {
        displayHeader();
        displayMenu();
        cin >> choice;
        processChoice(choice);
	} while (true);
}