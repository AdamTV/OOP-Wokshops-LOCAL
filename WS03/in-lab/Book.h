// Workshop:	3
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Book.h

#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict {
	const int max_title_size = 32;
	const int max_name_size = 16;
	const long long min_isbn_value = 1000000000000LL;
	const long long max_isbn_value = 9999999999999LL;
	class Book {
		char lastName[max_name_size +1];
		char firstName[max_name_size +1];
		long long ISBN;
		char title[max_title_size +1];
	public:
		void set(const char*,const char*,const char*,long long);
		bool isEmpty() const;
		void display() const;
	};
}

#endif // !SICT_BOOK_H
