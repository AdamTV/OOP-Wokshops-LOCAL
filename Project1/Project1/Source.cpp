#define _CRT_SECURE_NO_WARNINGS
//MIDTERM REVIEW
//NAME: ADAM STINZIANI
//DATE 2019-02-13
//FILE: ICECREAM.CPP
#include <cstring>
#include <iostream>
#include "IceCream.h"

using namespace std;

const int minScoops = 1;
const int maxScoops = 5;
const int emptyState = 0; //OUT OF SPECIFIED RANGE

IceCream::IceCream() {
	numOfScoops = emptyState;
}
IceCream::IceCream(int scoo, const char* flav) {
	set(scoo, flav);
}
void IceCream::set(int scoo, const char* flav) {
	if (scoo >= minScoops && scoo <= maxScoops) {
		numOfScoops = scoo;
		strncpy(flavour, flav, max_flavour_size);
	}
	else {
		*this = IceCream();
	}
}
bool IceCream::isEmpty() {
	bool empty = false;
	if (numOfScoops == emptyState)
		empty = true;
	return empty;
}
void IceCream::display(std::ostream&) {
	if (isEmpty()) {
		std::cout << "Argh!";
	}
	else {
		std::cout.fill('0');
		std::cout.width(3);			//ONLY APPLIES TO NEXT LINE	
		std::cout << numOfScoops << " " << flavour;
		std::cout.fill(' ');		//RESET 
		cout << endl;
	}
}
IceCream IceCream::operator++() {
	this->numOfScoops += 1;
	return *this;
}
IceCream& IceCream::operator-(int subtract) {
	if (subtract < 0)
		numOfScoops = 1;			//SAME AS this->numOfScoops = 1;
	if (numOfScoops - subtract < 1)
		numOfScoops = 1;
	else
		numOfScoops -= subtract;
	return *this;
}

int main() {
	int flavs = 3;
	IceCream* cones = nullptr;		//STORED IN STATIC MEMORY
	cones = new IceCream[flavs];	//ALLOCATES DYNAMIC MEMORY AT CONES ADDRESS
	cones[0] = IceCream(2, "Moose Tracks");
	cones[1] = IceCream(4, "Cookie Dough");
	cones[2] = IceCream(5, "Mint Chocolate");

	IceCream* tmp = nullptr;
	tmp = new IceCream[flavs + 1];	

	for (int i = 0; i < flavs; i++) {
		tmp[i] = cones[i];
	}
	delete[] cones;				//DELETE MEMORY AT CONES ADDRESS
	cones = tmp;				//CONES ADDRESS = TMP ADDRESS
	tmp = nullptr;
	cones[3] = IceCream(1, "Vanilla");
	for (int i = 0; i < flavs + 1; i++) {
		cones[i].display(std::cout);
		//cout << cones[i].flavours	GIVES ERROR
	}
	delete[] cones;
	cones = nullptr;
}