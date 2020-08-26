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
#include <list>
#include <vector>
#include "Autoshop.h"

namespace sdds {
	Autoshop& Autoshop:: operator+=(Vehicle* theVehicle) {
		
			m_vehicles.push_back(theVehicle);
			return *this;
		
	}
		// : adds the vehicle received as parameter into the m_vehicles vector.

	void Autoshop::display(std::ostream& out) const {
		
		out << "--------------------------------"<<std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		for (auto& i : m_vehicles) {
			i->display(out);
			out<< std::endl;
		}
		out << "--------------------------------"<<std::endl;
	}
		
	Autoshop::~Autoshop(){
		for (auto& i : m_vehicles) {
			delete i;
			i = nullptr;
		}
	}
	
}