// Workshop:	7
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Hero.h
#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
using namespace std;

namespace sict {
	const int max_rounds = 100, max_name_size = 41;
	class Hero {
		char fullName[max_name_size];
		unsigned int health;
		unsigned int strength;
	public:
		Hero(const char*, int, int);
		bool emptyState;
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
	};
	ostream& operator<<(ostream& os, const Hero& hero);
	const Hero& operator*(const Hero& first, const Hero& second);

}

#endif