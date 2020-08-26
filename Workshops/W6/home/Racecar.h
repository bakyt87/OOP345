// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.09.2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include <string>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;  //: the percentage(stored as a number between 0 an 1) by which this Racecar can boost its top speed.

	public:
		Racecar(std::istream& in);   // : calls the constructor from Car to build the subobject, 
		//and then it extracts the last field from the stream containing the booster bonus.
		//The input format for a racecar is TAG, MAKER, CONDITION, TOP_SPEED, BOOSTER
		void display(std::ostream& out) const; //: calls Car::display() to print the 
		//information about the car, and adds* at the end.The format should be | MAKER | CONDITION | TOP_SPEED | *
		double topSpeed() const;  // : returns the top speed of the car, including any booster effects.
		
		~Racecar() {}
	};
}

#endif