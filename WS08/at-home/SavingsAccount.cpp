// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		SavingsAccount.cpp

#include "SavingsAccount.h"

namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		if (interestRate > 0)
			currentInterest = interestRate;
		else
			currentInterest = 0;
	}
	void SavingsAccount::monthEnd() {
		
		credit(balance() * currentInterest);
	}
	void SavingsAccount::display(std::ostream& out) const {
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Account type: Savings\nBalance: $" << balance() << "\nInterest Rate (%): " << currentInterest * 100 << std::endl;
	}
}