/*
 * Banking.h
 *
 *  Created on: Feb 9, 2020
 *      Author: 1734833_snhu
 */

#ifndef BANKING_H_
#define BANKING_H_

class Banking {
public:
	Banking();

	// Functions to display the proper information to the user
	void PrintStaticReports();
	void PrintMnthlyDeposInfo();
	void PrintWithoutMnthlyDeposInfo();

	// Mutators to set values for the private data members, declared and defined here
	void setInitialInvestment(double t_initialInvest) { m_initialInvestment = t_initialInvest; };
	void setMonthlyDeposit(double t_mnthlyDepos) { m_monthlyDeposit = t_mnthlyDepos; };
	void setAnnualInterest(double t_annualInterest) { m_annualInterest = t_annualInterest; };
	void setNumOfYears(int t_numYears) { m_numOfYears = t_numYears; };

private:
	// Variables to hold the user's entered values
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numOfYears;
};

#endif /* BANKING_H_ */
