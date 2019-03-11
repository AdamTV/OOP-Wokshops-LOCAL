// Workshop:	7
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Hero.cpp
#include <cstring>
#include <iostream>
#include "Hero.h"

namespace sict {
	Hero::Hero(const char * name, int hp, int ap) {
		bool valid = hp > 0 && ap > 0;
		if (valid) {
			strncpy(fullName, name, max_name_size);
			health = hp, strength = ap;
		}
		else {
			emptyState = true;
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
			if (health < 0)
				health = 0;
		}
	}
	bool Hero::isAlive() const {
		bool valid = health > 0;
		return valid;
	}
	int Hero::attackStrength() const {

	}
	ostream& operator<<(ostream& os, const Hero& hero) {

	}
	const Hero& operator*(const Hero& first, const Hero& second) {

	}
}