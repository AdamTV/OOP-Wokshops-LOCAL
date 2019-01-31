#define _CRT_SECURE_NO_WARNINGS
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
	void Book::set(const char* firstName_n,const char* lastName_n,const char* title_n,long long ISBN_n) {
		ISBN = ISBN_n;
		int digits[isbn_size];
		long long tmpISBN = ISBN_n;
		for (int i = 0; i < isbn_size; i++) {
			int digit = tmpISBN % 10;
			digits[i] = digit;
			tmpISBN /= 10;
		}
		int oddDigits = 0;
		for (int i = 0; i < isbn_size; i += 2)
			oddDigits += digits[i];
		int evenDigits = 0;
		for (int i = 1; i < isbn_size; i += 2)
			evenDigits += digits[i];
		evenDigits *= 3;
		int evenOdd = evenDigits + oddDigits;
		int mod10 = evenOdd % 10;
		int subtract = 10 - mod10;
		int add = subtract + evenOdd;

		if (add / 10 == digits[isbn_size - 1] && ISBN_n > min_isbn_value && ISBN_n < max_isbn_value) {
			strncpy(firstName, firstName_n, max_name_size);
			firstName[max_name_size] = '\0';
 			strncpy(lastName, lastName_n, max_name_size);
			lastName[max_name_size] = '\0';
			strncpy(title, title_n, max_title_size);
			title[max_title_size] = '\0';
		}
		else
			ISBN = 0; // SAFE EMPTY STATE
	}
	void Book::set(int year_n, double price_n) {
		if (ISBN > 0) {
			year = year_n;
			price = price_n;
		}
	}
	bool Book::isEmpty() const {
		bool check;
		if (ISBN == 0)
		check = true;
		else
		 check = false;
		return check;
	}
	void Book::display(bool check) const {
		if (isEmpty()) {
			cout << "The book object is empty!" << endl;
		}
		else {
			cout << "Author: " << lastName << ", " << firstName << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << ISBN << endl;
		}	
	}
}
