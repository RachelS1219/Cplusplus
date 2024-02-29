#ifndef _TOOLS_H_
#define _TOOLS_H_
// declare functions here

// displays start menu
void displayStart();

// uses pass by references to assign user input to variables
void userInput(double& openAmt, double& monthlyDep, double& userRate,
	double& userYears);

// Verify user input is a double
double checkDbl(double returnInt);

// prints the users answers
void printUserInput(double openAmt, double monthlyDep, double userRate,
	double userYears);

// Prints menu without additional monthly deposits
void printNoDepDisplay();

// does calculations and prints without monthly deposits
void printNoDep(double openAmt, double userRate, double userYears);


// Prints menus with additional monthly deposits
void printYesDepDisplay();

// prints calculations for WITH monthly deposits
void printYesDep(double openAmt, double monthlyDep, double userRate, double userYears);
#endif
