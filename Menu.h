# pragma once
#include "main.h"
#include "StudentDatabase.h"

class Menu {
private:
	StudentDatabase db;
	void displayHeader();
	void displayMenu();
	void processChoice(char choice);

public:
	void run();
};