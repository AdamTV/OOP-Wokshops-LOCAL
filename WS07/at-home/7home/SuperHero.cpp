#define _CRT_SECURE_NO_WARNINGS
// Workshop:	7
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		SuperHero.cpp
#include "SuperHero.h"

namespace sict {
	SuperHero::SuperHero(const char* nm, int hp, int ap, int bs, int df) : Hero(nm, hp, ap) {
		bonus = bs, defence = df;
	}
	int SuperHero::attackStrength() const {
		return Hero::attackStrength() + bonus;
	}
	int SuperHero::defend() const {
		return defence;
	}
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		std::cout << "Super Fight! " << first << " vs " << second << " : ";
		SuperHero first_n = first, second_n = second;
		const SuperHero* winner;
		int win = 1;
		bool won = false;
		int i;
		for (i = 0; i < max_rounds && !won; i++) {
			first_n -= (second.attackStrength() - first.defend());
			second_n -= (first.attackStrength() - second.defend());
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
		const SuperHero& theWinner = *winner;
		std::cout << "Winner is " << theWinner << " in " << i << " rounds." << std::endl;
		return theWinner;
	}
}
