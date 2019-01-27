// Workshop 2
// Name: ADAM STINZIANI
// Student #: 124521188
// Course: OOP244 Winter 2019
// File: CellPhone.cpp

// TODO: include the necessary headers
#include <iostream>
#include "CellPhone.h"

using namespace std;

// TODO: the sict namespace
namespace sict {
	void display(const CellPhone & phone) {
		cout << "Phone " << phone.m_model <<
				" costs $" << phone.m_price << "!" << endl;
	}
	void display(const CellPhone phone[i], int count) {
		double cheap = 100000;
			cout << "------------------------------" << endl
			<< "Phones available at the mall :" << endl
			<< "------------------------------" << endl;
		for (int i = 0; i < count; i++) {
			cout << i << ". ";
		//	sict::display(phone[i]);
			//if (phone[i].m_price < cheap)
				//cheap = phone[i].m_price;
		}
		cout << "------------------------------" << endl
			 << " The cheapest phone costs $" << cheap
			 << "------------------------------" << endl;
	}
}

    // TODO: definition for display(...) 
