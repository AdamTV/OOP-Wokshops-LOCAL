// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		ALLOCATOR.h

#include "SavingsAccount.h"

namespace sict {
	const double theRate = 5;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(balance, theRate);
		}
		return account;
	}
}