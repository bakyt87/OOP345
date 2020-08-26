// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.09.2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <sstream>
#include "Utilities.h"
#include "Racecar.h"

namespace sdds {


	Vehicle* createInstance(std::istream& in) {
		
		std::string str;
		Vehicle* ptr = nullptr;
		getline(in, str);
		
			if (!str.empty()) {
				trim(str);
				std::stringstream car(str);
				if (str.at(0) == 'C' || str.at(0) == 'c') {
					
					ptr = new Car(car);
				}
				else if (str.at(0) == 'R' || str.at(0) == 'r') {
					
					ptr = new Racecar(car);
				}
				else {

					throw std::string("Unrecognized ") + "record type: " + "["+str.at(0) + "]";
				}
			}
		
			return ptr;
		}

	
}