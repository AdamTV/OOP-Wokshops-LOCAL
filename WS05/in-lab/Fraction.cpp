// Workshop:	5
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Fraction.cpp

// TODO: insert header files
#include <iostream>
#include "Fraction.h"

using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		a = 0;	//SAFE EMPTY STATE
		b = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int a_, int b_) {
		if (a_ >= 0 && b_ > 0) {
			Fraction ab;
			ab.a = a_, ab.b = b_;
			ab.reduce();
			a = ab.a;
			b = ab.b;
		}
		else {
			*this = Fraction();
		}
	}
	// TODO: implement the max query
	int Fraction::max() const {
		int max;
		if (a > b)
			max = a;
		else
			max = b;
		return max;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		int min;
		if (a < b)
			min = a;
		else
			min = b;
		return min;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	void Fraction::reduce() {
		int g_c_d = gcd();
		a /= g_c_d;
		b /= g_c_d;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty())
			cout << "no fraction stored";
		else if (b != 1)
			cout << a << "/" << b;
		else
			cout << a;
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool valid = false;
		if (a == 0 && b == 0)
			valid = true;
		return valid;
	}
	bool Fraction::bothEmpty(const Fraction& rhs) const {
		bool valid = false;
		if (isEmpty() && rhs.isEmpty())
			valid = true;
		return valid;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction result;
		if (bothEmpty(rhs)) {
			result = Fraction();
		}
		else {
			int ad = a * rhs.b;
			int bc = b * rhs.a;
			int bd = b * rhs.b;
			result.a = ad + bc;
			result.b = bd;
			result.reduce();
		}
		return result;
	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		Fraction result;
		if (bothEmpty(rhs)) {
			result = Fraction();
		}
		else {
			int ac = a * rhs.a;
			int bd = b * rhs.b;
			result.a = ac;
			result.b = bd;
			result.reduce();
		}
		return result;
	}
	bool Fraction::operator==(const Fraction& rhs) const {
		bool end;
		bool valid = rhs.a == a && rhs.b == b;
		if (valid && !bothEmpty(rhs))
			end = true;
		else
			end = false;
		return end;
	}
	bool Fraction::operator!=(const Fraction& rhs) const {
		bool valid;
		if (rhs == *this)
			valid = false;
		else if (bothEmpty(rhs))
			valid = false;
		else
			valid = true;
		return valid;
	}
	Fraction Fraction::operator+=(const Fraction& rhs) {
		if (!bothEmpty(rhs))
			*this = *this + rhs;
		else
			*this = Fraction();
		return *this;
	}
}