// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		ALLOCATOR.h

#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
	const double theRate = 0.05;
	const double theUseFee = 0.5;
	const double theMonthFee = 2;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(balance, theRate);
		}
		if (type[0] == 'C') {
			account = new ChequingAccount(balance, theUseFee, theMonthFee);
		}
		return account;
	}
}