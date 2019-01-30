// Workshop:	3
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Book.cpp

#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {
	void Book::set(const char firstName[MAX_NAME_SIZE],const char lastName[MAX_NAME_SIZE],const char title[MAX_TITLE_SIZE], long ISBN) {
		if (ISBN >= MIN_ISBN_VALUE && ISBN >= MIN_ISBN_VALUE)
			Book temp;
		strncpy((char*)firstName, temp.firstName, MAX_NAME_SIZE);
		else
			ISBN = 0;
	}
	bool Book::isEmpty() const {
		if (ISBN == 0)
			return true;
		else
			return false;
	}
	void Book::display() const {
		if (ISBN > 0) {
			cout << "Author:" << lastName << ", " << firstName << endl
				<< "Title: " << title << endl
				<< "ISBN-13: " << ISBN << endl;
		}
		else if (ISBN == 0) {
			cout << "The book object is empty!" << endl;
		}
	}
}