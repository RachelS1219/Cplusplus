#include <iostream>
#include <string>
#include <fstream>
#include "ProjectFunctions.h"
#include <conio.h>
#include <iomanip>
using namespace std;

void displayStart() {
	cout << "****************************************" << endl;
	cout << "************** Data Input **************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	system("pause"); // has user hit any key to continue (windows only?)
	cout << endl;
}

void userInput(double& openAmt, double& monthlyDep, double& userRate,
	double& userYears) {
	cout << "Enter Initial Deposit Amount:\n";
	openAmt = checkDbl(openAmt); // uses check double to verify input
	cout << "Enter Monthly Deposit (0 if none):\n";
	monthlyDep = checkDbl(monthlyDep);
	cout << "Enter Annual Interest Rate:\n";
	userRate = checkDbl(userRate);
	cout << "Enter Number of Years:\n";
	userYears = checkDbl(userYears);
	cout << endl;
	
}

double checkDbl(double returnInt) {
	int error = 0;
	while (error == 0) {
		cin >> returnInt;
		if (cin.fail()) {
			cout << "Please enter a valid integer\n" << endl;
			cin.clear();
			cin.ignore(80, '\n');
		}
		else {
			error = 1;
		}
	}
	return returnInt;
}

void printUserInput(double openAmt, double monthlyDep, double userRate,
	double userYears) {
	cout << "****************************************" << endl;
	cout << "************** Data Input **************" << endl;
	cout << "Initial Investment Amount: $" << fixed << setprecision(2) << openAmt << endl;
	cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthlyDep << endl;
	cout << "Annual Interest: %" << fixed << setprecision(2) << userRate << endl;
	cout << "Number of years: " << fixed << setprecision(2) << userYears << endl;
	system("pause");
	cout << endl;
}

void printNoDepDisplay() {
	cout << left << setw(64) << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << left << setw(64) << "================================================================" << endl;
	cout << setw(12) << "  Year" << setw(24) << "Year End Balance" << "Year End Earned Interest" << endl;
	cout << left << setw(64) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void printNoDep(double openAmt, double userRate, double userYears) {
	int i;
	int year = 1;
	double interest = 0;
	double totalInterest = 0;

	// calculates and writes year then total then years interest to file then newline
	for (i = 0; i < userYears; i++) {
		int i2 = 0;
		for (i2 = 0; i2 < 12; i2++) {// this will compound for 12 months for total yearly interest
			interest = (openAmt * (userRate / 100) / 12);
			openAmt = openAmt + interest;
			totalInterest = totalInterest + interest;
		}
		cout << right << setw(6) << fixed << setprecision(0) << year;
		cout << right << setw(22) << fixed << setprecision(2) << openAmt;
		cout << right << setw(32) << totalInterest;
		cout << endl;
		year += 1;
	}
	cout << endl;
}


void printYesDepDisplay() {
	cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
	cout << left << setw(64) << "================================================================" << endl;
	cout << setw(12) << "  Year" << setw(24) << "Year End Balance" << "Year End Earned Interest" << endl;
	cout << left << setw(64) << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
	
}

void printYesDep(double openAmt, double monthlyDep, double userRate, double userYears) {
	int i;
	int year = 1;
	double interest = 0;
	double totalInterest = 0;

	// calculates and writes year then total then years interest to file then newline
	for (i = 0; i < userYears; i++) {
		int i2 = 0;
		for (i2 = 0; i2 < 12; i2++) {// this will compound for 12 months for total yearly interest
			interest = ((openAmt + monthlyDep) * (userRate / 100) / 12);
			openAmt = (openAmt + monthlyDep) + interest;
			totalInterest = totalInterest + interest;
		}
		cout << right << setw(6) << fixed << setprecision(0) << year;
		cout << right << setw(22) << fixed << setprecision(2) << openAmt;
		cout << right << setw(32) << totalInterest;
		cout << endl;
		year += 1;
	}
}