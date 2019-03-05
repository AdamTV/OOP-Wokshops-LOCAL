// Workshop:	6
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Contact.h
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#endif // !SICT_CONTACT_H

namespace sict {
	const int max_name_size = 16;
	const int max_number_size = 12;
	const long long twoDigCode = 100000000000;
	const long long maxPhoneNumber = 1000000000000;
	class Contact {
		char fullName[max_name_size];
		//long long number[max_number_size + 1];
		long long* numbers = nullptr;
		int numbersStored;
		bool emptyState;
	public:
		Contact();
		Contact(const char* name,const long long nums[], int count);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool checkNumber(long long);
		void newNumber(long long, int count);
		void displayNumber(long long) const;
		int* breakNumber(long long) const;
	};
}
