// OOP244 Workshop 9: Function Templates
// File: Data.cpp
// Version: 2.0.1
// Date: 2017/12/17
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the answers and readRow functions
// Chris     2017.12.17 removed answers to Q1
///////////////////////////////////////////////////

#include "Data.h"
using namespace std;

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		double change = ((double) population[n - 1] - (double)population[0]) / (double)1000000;
		cout << "Population change from 2000 to 2004 is " << fixed << setprecision(2) << change << " million\n";

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2004
		bool crimeRate = false;
		if (violentCrimeRate[n - 1] > violentCrimeRate[0])
			crimeRate = true;
		cout << "Violent Crime trend is "; crimeRate ? cout << "up\n" : cout << "down\n";


		// Q3 print the GTA number accurate to 0 decimal places
		double theaverage = 0;
		theaverage = average(grandTheftAuto, n);
		cout << "There are " << theaverage << " million Grand Theft Auto incidents on average a year\n";

		// Q4. Print the min and max violentCrime rates
		double lowest, highest;
		lowest = min(violentCrimeRate, n);
		highest = max(violentCrimeRate, n);
		cout << "The Minimum Violent Crime rate was " << setprecision(0) << lowest 
			<< "\nThe Maximum Violent Crime rate was "
			<< highest << setprecision(6); cout.unsetf(ios::fixed); cout.unsetf(ios::right);
	}
}