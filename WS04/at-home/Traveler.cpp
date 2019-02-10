#define _CRT_SECURE_NO_WARNINGS
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
	void Traveler::set(const char frst[], const char last[], const char dest[], int year, int month, int day) {
		strncpy(firstName, frst, max_name_size);
		strncpy(lastName, last, max_name_size);
		strncpy(destination, dest, max_destination_size);
		flightYear = year, flightMonth = month, flightDay = day;
	}

	// TODO: implement the default constructor here
	Traveler::Traveler() {
		firstName[0] = '\0';	//SAFE EMPTY STATE
		flightYear = 0;
	}
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char frst[], const char last[], const char dest[]) {
		bool valid = frst != nullptr && last != nullptr && dest != nullptr && frst[0] != '\0' && last[0] != '\0' && dest[0] != '\0';
		if (valid) {
			set(frst, last, dest, 2019, 7, 1);
		}
		else {
			*this = Traveler();
		}
	}
	Traveler::Traveler(const char frst[], const char last[], const char dest[], int year, int month, int day) {
		bool valid = year >= 2019 && year <= 2022 && month >= 1 && month <= 12 && day >= 1 && day <= 31;
		if (valid) {
			*this = Traveler(frst, last, dest);
			if (firstName[0] != '\0') {
				set(frst, last, dest, year, month, day);
			}
		}
		else {
			*this = Traveler();
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
		if (isEmpty()) {
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else
		{
			cout << lastName << ", " << firstName << " goes to " << destination <<
				" on " << flightYear << "/";
			cout.fill('0');
			cout.width(2);
			cout << flightMonth << "/";
			cout.width(2);
			cout << flightDay << endl;
		}
	}
	const char* Traveler::name() const {
		const char* check = nullptr;
		if (firstName[0] != '\0')
			check = firstName;
		return check;
	}
	bool Traveler::canTravelWith(const Traveler& traveler) const {
		bool check;
		if (strcmp(destination, traveler.destination) == 0 && flightDay == traveler.flightDay && flightMonth == traveler.flightMonth && flightYear == traveler.flightYear)
			check = true;
		else
			check = false;
		return check;
	}
}
