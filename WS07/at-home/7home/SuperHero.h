// Workshop:	7
// Name:		ADAM STINZIANI
// Student #:	124521188
// Course:		OOP244 Winter 2019
// File:		SuperHero.h
#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"
namespace sict {
	class SuperHero : public Hero {
		int bonus, defence;
	public:
		SuperHero(const char* , int , int, int, int);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif
