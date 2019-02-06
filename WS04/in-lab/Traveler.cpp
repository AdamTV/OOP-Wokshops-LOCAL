// TODO: add file header comments here
// Workshop:	4
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Traveler.cpp

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Traveler.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Traveler::Traveler() {
		firstName[0] = '\0';	//SAFE EMPTY STATE
	}
    // TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char frst[], const  char last[], const  char dest[]) {
		bool valid = frst != nullptr && last != nullptr && dest != nullptr && frst[0] != '\0' && last[0] != '\0' && dest[0] != '\0';
		if (valid) {
			strncpy(firstName, frst, max_name_size);
			strncpy(lastName, last, max_name_size);
			strncpy(destination, dest, max_destination_size);
		}
		else {
			firstName[0] = '\0';
		}
	}
    // TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool check;
		if (firstName[0] == '\0')
			check = true;
		else
			check = false;
		return check;
	}
    // TODO: implement display query here
	void Traveler::display() const {
		if (isEmpty())
			cout << "--> Not a valid traveler! <--" << endl;
		else
			cout << firstName <<" "<< lastName << " goes to "<< destination<< endl;
	}
}

