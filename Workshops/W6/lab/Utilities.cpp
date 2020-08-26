// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds {


	Vehicle* createInstance(std::istream& in) {
		std::string str;
		Vehicle* ptr = nullptr;
		getline(in, str);
		if (!str.empty()) {
			trim(str);
			if (str.at(0) == 'C' || str.at(0) == 'c') {
				std::stringstream car(str);
				ptr = new Car(car);
			}


		}
		return ptr;
	}
}