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
	}
	Contact::Contact(const char* name, const long long nums[], int count) {
		if (count == 0)
			numbersStored = count;
		if (name != nullptr && name[0] != '\0')
			strncpy(fullName, name, max_name_size);
		else
			*this = Contact();
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
		/*cout << "(+";
		if (number > twoDigCode) {
			cout << nums[0];
		}
		cout << nums[1] << ") " << nums[2] <<
			nums[3] << nums[4] << " " << nums[5] << nums[6] << nums[7]
			<< "-" << nums[8] << nums[9] << nums[10] << nums[11] << endl; //DOESNT WORK???*/
		if (number > twoDigCode)
			cout << "(+" << nums[0] << nums[1] << ") " << nums[2] <<
			nums[3] << nums[4] << " " << nums[5] << nums[6] << nums[7]
			<< "-" << nums[8] << nums[9] << nums[10] << nums[11] << endl;
		else
			cout << "(+" << nums[1] << ") " << nums[2] << nums[3] <<
			nums[4] << " " << nums[5] << nums[6] << nums[7] << "-" <<
			nums[8] << nums[9] << nums[10] << nums[11] << endl;
	}

	int* Contact::breakNumber(long long number) const {
		long long tmpNumber = number;
		int nums[max_number_size];
		for (int i = max_number_size - 1; i >= 0; i--) {
			int digit = tmpNumber % 10;
			nums[i] = digit;
			tmpNumber /= 10;
		}
		return nums;
	}
}