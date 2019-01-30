// Workshop:	3
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Book.h

#ifndef SICT_BOOK_H
#define SICT_BOOK_H

#define MAX_TITLE_SIZE 32	//PUT IN NAMESPACE???
#define MAX_NAME_SIZE 16
#define MIN_ISBN_VALUE 1000000000000
#define MAX_ISBN_VALUE 9999999999999

namespace sict {
	class Book {
		char lastName[MAX_NAME_SIZE];
		char firstName[MAX_NAME_SIZE];
		long ISBN;
		char title[MAX_TITLE_SIZE];
	public:
		void set(const char[MAX_NAME_SIZE],const char[MAX_NAME_SIZE],const char[MAX_TITLE_SIZE], long ISBN);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SICT_BOOK_H
