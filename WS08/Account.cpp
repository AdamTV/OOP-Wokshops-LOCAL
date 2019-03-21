// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Account.cpp
#include "Account.h"

namespace sict {
	double Account::balance() const {
		return currentBalance;
	}
	Account::Account(double balance) {
		if (balance > 0)
			currentBalance = balance;
		else
			currentBalance = 0;
	}
	bool Account::credit(double amount) {
		bool check = true;
		if (amount > 0)
			currentBalance += amount;
		else
			check = false;
		return check;
	}
	bool Account::debit(double amount) {
		bool check = true;
		if (amount > 0)
			currentBalance -= amount;
		else
			check = false;
		return check;
	}
}