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
}

    // TODO: definition for display(...) 
