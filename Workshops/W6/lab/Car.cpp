// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& is) {
		std::string str;
		getline(is, str, ',');
		getline(is, str, ',');
		trim(str);
		car_maker = str;
		getline(is, str, ',');
		trim(str);
		if (str.at(0) == 'n') {
			car_condition = Condition::New;
		}
		else if (str.at(0) == 'u') {
			car_condition = Condition::Used;
		}
		else if (str.at(0) == 'b') {
			car_condition = Condition::Broken;
		}
		else {
			car_condition = Condition::Invalid;
		}
		getline(is, str);
		car_topSpeed = stod(str);

	}
	/*a custom constructor that receives an object of type std::istream& as parameter. This constructor should be able to read a single 
	record from the stream, extract all the information about a single car and store it in the attributes. Each record has the following format:
TAG,MAKER,CONDITION,TOP_SPEED
TAG, is a single character representing the type of vehicle: c or C for car. Any other tag is considered invalid.
MAKER, the name of the company that makes the car
CONDITION, a single character: n for new, u for used, and b for broken. Any other character is considered invalid.
TOP_SPEED, an integer containing the maximum speed the vehicle can achieve. If the content of this field is not a number, then the field is considered invalid.
any space at the beginning/end of each field should be removed.*/
	std::string Car::condition() const { 
		std::string str;
		if (car_condition == Condition::New) {
			str = "new";
        }
		else if (car_condition == Condition::Broken) {
			str = "broken";
		}
		else if (car_condition == Condition::Used) {
			str = "used";
		}
		else {
			str = "invalid";
		}
		
		return str; 
	} //: a query that returns new, used or broken, representing the condition of the car
	double Car:: topSpeed() const { return car_topSpeed; }
	
	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::setw(10);
		out << car_maker << " | ";
		out << std::setw(6)<<std::left;
		out << condition() << " | ";
		out << std::setw(6)<<std::right<<std::fixed;
		out<<std::setprecision(2);
                out << topSpeed() << " |";
                out.unsetf(std::ios::fixed);

	}/* a query that inserts in the first parameter the content of the car object in the format | MAKER | CONDITION | TOP_SPEED | , where
		MAKER, field of size 10
		CONDITION, field of size 6
		TOP_SPEED, field of size 6, with two significant digits after the period
		see alignment in the sample output.*/
	void trim(std::string& str) {
		size_t t = str.find_first_not_of(' ');
		str = str.substr(t, str.find_last_not_of(' ') - t + 1);
	}


}