//MIDTERM REVIEW
//NAME: ADAM STINZIANI
//DATE 2019-02-13
//FILE: ICECREAM.h
#include <iostream>
const int max_flavour_size = 18;
class IceCream {
	int numOfScoops;
	char flavour[max_flavour_size + 1];
public:
	IceCream();
	IceCream(int, const char*);
	void set(int, const char*);
	bool isEmpty();
	void display(std::ostream&);
	IceCream operator++();
	IceCream& operator-(int);
};