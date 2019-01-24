// Workshop 2
// Name: ADAM STINZIANI
// Student #: 124521188
// Course: OOP244 Winter 2019
// File: CellPhone.h

// TODO: header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H

#define mMODEL 31

// TODO: sict namespace
namespace sict {
	class CellPhone {
	public:
		char m_model[mMODEL];
		double m_price;
	};
		void display(const CellPhone & phone);
}


// TODO: define the structure CellPhone in the sict namespace

// TODO: declare the function display(...),
//         also in the sict namespace

#endif // !SICT_CELLPHONE_H