// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.09.2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in):Car(in) {
		std::string str;
		getline(in, str);
		
		if (!str.empty()) {
			m_booster = stod(str);
		}
		else {
			m_booster = 0.0;
		}

	}// : calls the constructor from Car to build the subobject, 
	//and then it extracts the last field from the stream containing the booster bonus.
	//The input format for a racecar is TAG, MAKER, CONDITION, TOP_SPEED, BOOSTER
	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";

	}//: calls Car::display() to print the 
	//information about the car, and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *
	double Racecar::topSpeed() const {
	return Car::topSpeed() *(1+ m_booster);
	}// : returns the top speed of the car, including any booster effects.

}