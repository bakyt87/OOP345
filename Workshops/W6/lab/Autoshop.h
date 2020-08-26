// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; //: a vector that store all the vehicles available at this autoshop.
	public:

		Autoshop& operator +=(Vehicle* theVehicle); // : adds the vehicle received as parameter into the m_vehicles vector.

		void display(std::ostream& out) const; // : iterates over the vehicles stored in m_vehiclesand prints them
		/* into the parameter(use Vehicle::display()) using the format :

		--------------------------------
			| Cars in the autoshop!|
			--------------------------------
			VEHICLE
			VEHICLE
			...
			--------------------------------*/
		~Autoshop();
	};
}

#endif 