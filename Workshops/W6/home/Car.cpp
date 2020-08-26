// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 06.09.2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.
#include <iomanip>
#include <string>
#include <iostream>
#include "Car.h"


namespace sdds {
	Car::Car(std::istream& is) {
		std::string str;
		getline(is, str, ',');
		getline(is, str, ',');
		trim(str);
		car_maker = str;
		getline(is, str, ',');
		
		if (str.find_first_not_of(' ') != std::string::npos) {
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
			throw std::string("Invalid record!");
		}
		}
		else {
			car_condition = Condition::New;
		}
			
			getline(is, str, ',');
			trim(str);
			if (str.find_first_of("0123456789.") == std::string::npos) {
				throw std::string("Invalid record!");
			}
			else
			{
            car_topSpeed = stod(str);
			}
    }
	
	
	std::string Car::condition() const { //: a query that returns new, used or broken, representing the condition of the car
		std::string car;
		if (car_condition == Condition::New) car = "new";

		else if (car_condition == Condition::Used) car = "used";
        
		else if (car_condition == Condition::Broken) car = "broken";
		
		else car = "invalid";
		
		
		return car; 
	} 
	double Car::topSpeed() const { return car_topSpeed; }
	
	void Car::display(std::ostream& out) const {
		out << "| ";
		out << std::setw(10);
		out << car_maker << " | ";
		out << std::setw(6)<<std::left;
		out << condition() << " | ";
		out << std::setw(6)<<std::right<<std::fixed << std::setprecision(2);
	    out << topSpeed() << " |";
		out.unsetf(std::ios::fixed);
	}
	/* a query that inserts in the first parameter the content of the car object in the format | MAKER | CONDITION | TOP_SPEED | , where
		MAKER, field of size 10
		CONDITION, field of size 6
		TOP_SPEED, field of size 6, with two significant digits after the period
		see alignment in the sample output.*/
	void trim(std::string& str) {
		size_t t = str.find_first_not_of(' ');
		str = str.substr(t, str.find_last_not_of(' ') - t + 1);
	}


}