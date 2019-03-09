#define _CRT_SECURE_NO_WARNINGS
// Workshop:	6
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Contact.cpp
#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact() {
		emptyState = true;
		numbers = nullptr;
	}
	Contact::Contact(const char* name, const long long nums[], int count) {
		strncpy(fullName, name, max_name_size);
		if (fullName[0] != '\0') {

			emptyState = false;
		}

		else {
			*this = Contact();
		}
		numbersStored = 0;
		for (int i = 0; i < count; i++) {
			if (checkNumber(nums[i])) {
				numbersStored++;
				newNumber(nums[i], numbersStored);
			}
		}
	}
	Contact::~Contact() {
		delete[] numbers;
		numbers = nullptr;
	}
	Contact::Contact(const Contact& rhs) {
		numbers = nullptr;
		*this = rhs;
	}
	Contact& Contact::operator=(const Contact& rhs) {
		if (this != &rhs) {
			strncpy(fullName, rhs.fullName, max_name_size);
			numbersStored = rhs.numbersStored;
			emptyState = rhs.emptyState;
			delete[] numbers;
			if (rhs.numbers != nullptr) {
				numbers = new long long[numbersStored];
				for (int i = 0; i < numbersStored; i++)
					numbers[i] = rhs.numbers[i];
			}
			else {
				numbers = nullptr;
			}
		}
		return *this;
	}
	Contact& Contact::operator+=(long long num) {
		if (checkNumber(num)) {
			numbersStored++;
			newNumber(num, numbersStored);
		}
		return *this;
	}
	bool 	Contact::isEmpty() const {
		bool check = false;
		if (emptyState == true)
			check = true;
		return check;
	}
	void 	Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << fullName << endl;
			for (int i = 0; i < numbersStored; i++)
				displayNumber(numbers[i]);
		}
	}
	bool Contact::checkNumber(long long num) {
		bool valid = false;
		int* digits;
		digits = breakNumber(num);
		int countryCode = 0;
		if (digits[0] != 0)
			countryCode++;
		if (digits[1] != 0)
			countryCode++;
		if (countryCode == 1 || countryCode == 2) {
			if (digits[2] != 0 && digits[5] != 0)
				valid = true;
		}
		if (num > maxPhoneNumber)
			valid = false;
		return valid;
	}
	void Contact::newNumber(long long number, int count) {
		if (numbers != nullptr) {
			long long * tmp = nullptr;
			tmp = new long long[count];
			for (int i = 0; i < count - 1; i++)
				tmp[i] = numbers[i];
			tmp[count - 1] = number;
			delete[] numbers;
			numbers = tmp;
			tmp = nullptr;
		}
		else {
			numbers = new long long[count];
			numbers[count - 1] = number;
		}
	}
	void Contact::displayNumber(long long number) const {
		int* nums;
		nums = breakNumber(number);
		int number_n[max_number_size];
		for (int i = 0; i < max_number_size; i++)
			number_n[i] = nums[i];
		cout << "(+";
		if (number > twoDigCode) {
			cout << number_n[0];
		}
		cout << number_n[1] << ") " << number_n[2] <<
			number_n[3] << number_n[4] << " " << number_n[5] << number_n[6] << number_n[7]
			<< "-" << number_n[8] << number_n[9] << number_n[10] << number_n[11] << endl;
	}

	int* Contact::breakNumber(long long number) const {
		long long tmpNumber = number;
		int nums[max_number_size];
		for (int i = max_number_size - 1; i >= 0; i--) {
			int digit = tmpNumber % 10;
			nums[i] = digit;
			tmpNumber /= 10;
		}
		int * nums_n = nums;
		return nums_n;
	}
}
