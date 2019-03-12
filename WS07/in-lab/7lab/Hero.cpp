#define _CRT_SECURE_NO_WARNINGS
// Workshop:	7
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		Hero.cpp

#include <cstring>
#include <iostream>
#include "Hero.h"

namespace sict {
	Hero::Hero() {
		emptyState = true;
	}
	Hero::Hero(const char * name, int hp, int ap) {
		bool valid = hp > 0 && ap > 0;
		if (valid) {
			strncpy(fullName, name, max_name_size);
			health = hp, strength = ap;
			emptyState = false;
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
		int streg;
		if (emptyState)
			streg = 0;
		else
			streg = strength;
		return streg;
	}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (!hero.emptyState)
			os << hero.fullName;
		else
			os << "No hero";
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		std::cout << "Ancient Battle! " << first << " vs " << second << " : ";
		Hero first_n = first, second_n = second;
		const Hero* winner;
		int win = 1;
		bool won = false;
		int i;
		for (i = 0; i < max_rounds && !won; i++) {
			first_n -= second.attackStrength();
			second_n -= first.attackStrength();
			if (!first_n.isAlive()) {
				win = 2;
				won = true;
			}
			if (!second_n.isAlive()) {
				won = true;
			}
		}
		if (win == 1)
			winner = &first;
		else
			winner = &second;
		const Hero& theWinner = *winner;
		std::cout << "Winner is " << theWinner << " in " << i << " rounds." << std::endl;
		return theWinner;
	}
}