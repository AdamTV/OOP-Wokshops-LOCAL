// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		SavingsAccount.h

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double currentInterest;
	public:
		SavingsAccount(double balance, double interestRate);
		~SavingsAccount()=default;
		void monthEnd();
		void display(std::ostream& out) const;
	};
	iAccount* CreateAccount(const char* type, double balance);
}

#endif