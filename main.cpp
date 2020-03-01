/*
 * main.cpp
 *
 *  Created on: Feb 11, 2020
 *      Author: Bailey Barton
 */
#include <iostream>
#include <exception>
#include <cctype>
#include "Banking.h"

using namespace std;

// This function is called initially and repeatedly if the user wants to try different values to alter their investment growth
void userAmts(Banking& investmentSimul) {
	double mnthlyDepos;
	double annualInterest;
	int numYears;

	// These ask for and acquire values for each needed variable that will help show investment growth
	cout << "Monthly Deposit: $";
	cin >> mnthlyDepos;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> numYears;

	// Here each value is being set to their respected private class data member
	investmentSimul.setMonthlyDeposit(mnthlyDepos);
	investmentSimul.setAnnualInterest(annualInterest);
	investmentSimul.setNumOfYears(numYears);

	// Program is paused here until the user types enter
	cin.sync();
	cout << "Press enter to continue...";
	cin.get();
}

// Function takes new user input or quits the program depending on user choice
void userChoice(Banking& investmentSimul) {
	char choice;
	string excessInput; // This is used for cases when the choice input is greater than one value

	// Loop to continue allowing user to try different values or exit if they are finished
	while(true) {
		userAmts(investmentSimul);
		investmentSimul.PrintStaticReports();

		// Loops until a valid input is given
		while (true) {
			try { // Try:catch is used to handle any incorrect input

				// Here a check is made to see if the user wants to try different values
				cout << "\nWould you like to try different monthly deposit, annual interest, and number of years values? (y/n)\n" << endl;
				cin >> choice;

				if (tolower(choice) == 'y' || tolower(choice) == 'n') {
					break;
				}
				cout << "Incorrect input, (y/n)" << endl;
				getline(cin, excessInput);

			} catch(exception& e) {
				cout << "Incorrect input, (y/n)" << endl;
				getline(cin, excessInput);
			}
		}

		// If user chooses "no", then the loop is exited and notified of it exiting
		if (choice == 'n') {
			break;
		}
	}
}

// Main function where everything is called and tied together
int main() {
	Banking investmentSimulation;
	double initialInvest; //Declared in main as it

	// Welcomes the user and then asks for the initial investment value, which will be constant throughout the program
	cout << "Welcome to the Airgead Banking investment growth simulator" << endl << endl;
	cout << "****************************************\n   *********** DATA INPUT ***********\n****************************************\n" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialInvest; // This is left in main as the initialInvestment value does not change

	investmentSimulation.setInitialInvestment(initialInvest);
	userChoice(investmentSimulation);

	cout << "Exiting program...";

	return 0;
}
