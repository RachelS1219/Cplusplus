// Rachel Stevenson Project 2

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "ProjectFunctions.h"

int main() {
	// open output file stream
	ofstream outFS;
	// initialize all variables
	double openAmt = 100;
	double monthlyDep = 10;
	double userRate = 10;
	double userYears = 5.00;
	double totalAmt = 0;
	double monthsFromYears = 0;
	double interest = 0;
	double totalSum = 0;

	// integer for loop
	int repeat = 0;

	// displays menu for input
	displayStart();

	while (repeat == 0) {

		// gets user input information and verifies/assigns variables (pass by)
		userInput(openAmt, monthlyDep, userRate, userYears);

		// prints user input to show what's entered
		printUserInput(openAmt, monthlyDep, userRate, userYears);

		// functions to do calculations and print with NO deposit
		printNoDepDisplay();
		printNoDep(openAmt, userRate, userYears);

		// functions to do calculations and print WITH deposit
		printYesDepDisplay();
		printYesDep(openAmt, monthlyDep, userRate, userYears);

		cout << "\nType 0 if you'd like to play again." << endl;
		cin >> repeat;
	}
	exit(0);
}
