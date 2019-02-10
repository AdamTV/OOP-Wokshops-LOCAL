// TODO: add file header comments here
// Workshop:	4
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Traveler.h

// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

// TODO: declare your namespace here
namespace sict {

	// TODO: define the constants here
	const int max_destination_size = 32;
	const int max_name_size = 16;

		// TODO: define the Traveler class here
	class Traveler {
		char firstName[max_name_size + 1];
		char lastName[max_name_size + 1];
		char destination[max_destination_size + 1];
		int flightYear;
		int flightMonth;
		int flightDay;
	public:
		void set(char*, char*, char*, int, int, int);
		Traveler();
		Traveler(char*, char*, char*);
		Traveler(char*, char*, char*, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler&) const;
	};
}
#endif // !SICT_TRAVELER_H