// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Autoshop.h"
//std::vector<Vehicle*> m_vehicles
namespace sdds {
	Autoshop& Autoshop:: operator +=(Vehicle* theVehicle) {
		
			m_vehicles.push_back(theVehicle);
			return *this;
		
	}
		// : adds the vehicle received as parameter into the m_vehicles vector.

	void Autoshop::display(std::ostream& out) const {
		std::vector<int> i;
		out << "--------------------------------"<<std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto& i: m_vehicles) {
			i->display(out);
			out<< std::endl;
		}
		out << "--------------------------------"<<std::endl;
	}
		// : iterates over the vehicles stored in m_vehiclesand prints them
	/* into the parameter(use Vehicle::display()) using the format :

	--------------------------------
		| Cars in the autoshop!|
		--------------------------------
		VEHICLE
		VEHICLE
		...
		--------------------------------*/
	Autoshop::~Autoshop(){
		for (auto& i : m_vehicles) {
			delete i;
                        i=nullptr;
		}
	}
}