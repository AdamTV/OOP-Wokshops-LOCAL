// Workshop:	8
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		ChequingAccount.cpp

#include "ChequingAccount.h"

namespace sict {
	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) :Account(balance) {
		if (transFee > 0)
			useFee = transFee;
		else
			useFee = 0;
		if (monthlyFee > 0)
			monthFee = monthlyFee;
		else
			monthFee = 0;
	}
	bool ChequingAccount::credit(double amount) {
		bool check = false;
		if (Account::credit(amount)) {
			check = true;
			Account::debit(useFee);
		}
		return check;
	}
	bool ChequingAccount::debit(double amount) {
		bool check = false;
		if (Account::debit(amount)) {
			check = true;
			Account::debit(useFee);
		}
		return check;
	}
	void ChequingAccount::monthEnd(){
		Account::debit(monthFee);
	}
	void ChequingAccount::display(std::ostream& out) const {
		out.setf(std::ios::fixed);
		out.precision(2);
		out << "Account type: Chequing\n Balance: $" << balance()
			<< "\nPer Transaction Fee: " << useFee << "\nMonthly Fee: " <<
			monthFee << std::endl;
	}
}