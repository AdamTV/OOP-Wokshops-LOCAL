// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Account.h

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {
	class Account : public iAccount {
		double currentBalance;
	protected:
		double balance() const;
	public:
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	};
	iAccount* CreateAccount(const char* type, double balance);
}

#endif
