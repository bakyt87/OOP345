// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.09.2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; //: a vector that store all the vehicles available at this autoshop.
	public:

		Autoshop& operator+=(Vehicle* theVehicle); // : adds the vehicle received as parameter into the m_vehicles vector.

		void display(std::ostream& out) const; // : iterates over the vehicles stored in m_vehiclesand prints them
		
		~Autoshop();
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto& car: m_vehicles) {
				if (test(car)) vehicles.push_back(car);
				
			}
		}   /*a template function that iterates over the vehicles stored in the m_vehicles, 
	 and adds to the second parameter all vehicles for which the test is true. The first
	 
	 parameter (test) can be a lambda expression, a pointer to a function, or a functor that matches the prototype:

     bool func(const sdds::Vehicle*);
Since this is a template function, it must be implemented in the header! The class is not a template.*/
	};
}

#endif 