// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <fstream>
#include <string>
#include "Vehicle.h"

enum class Condition : char { New, Used, Broken, Invalid };


namespace sdds{

	class Car :public Vehicle {
		std::string car_maker{};
		Condition car_condition{};
		double car_topSpeed{};

	public:

		Car(std::istream& is);
		std::string condition() const; //: a query that returns new, used or broken, representing the condition of the car
		double topSpeed() const; //
		void display(std::ostream& out) const; 
		/* , a query that inserts in the first parameter the content of the
		car object in the format | MAKER | CONDITION | TOP_SPEED | , where
			MAKER, field of size 10
			CONDITION, field of size 6
			TOP_SPEED, field of size 6, with two significant digits after the period
			see alignment in the sample output.*/
		

	};

         void trim(std::string&);

}





#endif // !SDDS_CAR_H

