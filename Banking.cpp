/*
 * Banking.cpp
 *
 *  Created on: Feb 9, 2020
 *      Author: 1734833_snhu
 */

#include <iostream>
#include <iomanip>
#include "Banking.h"

using namespace std;

// Default constructor
Banking::Banking () {
	m_initialInvestment = 0.0;
	m_monthlyDeposit = 0.0;
	m_annualInterest = 0;
	m_numOfYears = 0;
}

// Prints the static report values for investments with monthly deposits
void Banking::PrintMnthlyDeposInfo(){
	int i, j;
	double interestAmt;
	double endBalance = m_initialInvestment;

	// Loops to acquire the year end balance and year end earned interest for each year
	for (i = 1; i <= m_numOfYears; ++i) {
		double yearTotInt = 0;

		// Loops to add the monthly deposit added for each month in a year
		for (j = 1; j <= 12; ++j) {
			interestAmt = (endBalance + m_monthlyDeposit) * ((m_annualInterest / 100.0) / 12);

			yearTotInt = yearTotInt + interestAmt;

			endBalance = endBalance + m_monthlyDeposit + interestAmt;
		}

		cout << i << fixed << setprecision(2) << "\t|\t$" << endBalance << "      |      $" << yearTotInt << endl;
	}

}

// Prints the static report values for investments without monthly deposits
void Banking::PrintWithoutMnthlyDeposInfo(){
	int i;
	double endBalance = m_initialInvestment;
	double interestAmt;

	// Loops to acquire the year end balance and year end earned interest for each year
	for (i = 1; i <= m_numOfYears; ++i) {

		interestAmt = endBalance * (m_annualInterest / 100.0);

		endBalance = endBalance + interestAmt;

		cout << i << fixed << setprecision(2) <<  "\t|\t$" << endBalance << "\t\t|\t$" << interestAmt << endl;
	}

}

// Prints both static reports displaying the investment growth without monthly deposits and with monthly deposits
void Banking::PrintStaticReports() {
	cout << "\n  Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year       Year End Balance        Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;
	PrintWithoutMnthlyDeposInfo();

	cout << "\n  Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "============================================================" << endl;
	cout << "Year       Year End Balance        Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------" << endl;
	PrintMnthlyDeposInfo();
}
