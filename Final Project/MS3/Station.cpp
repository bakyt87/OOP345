// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;


	size_t Station::m_widthField = 0;
	int Station::id_generator = 1;

	Station::Station() {

		m_id = 0;             //the id of a station(integer)
		station_name = "";	       //the name of the item handled that the station(array of characters)
		description = "";     //the description of the station(array of characters)
		m_serialNum = 0;     //the next serial number to be assigned to an item at this station(integer)
		m_numOfItem = 0;    //the number of current items left in stock(integer)
	}
	Station::Station(const std::string& str) {
		bool more = true;
		size_t end = 0;
		size_t cnt = 0;
		Utilities obj; // used to extract tokens

		m_id = id_generator;
		id_generator++;


		//obj.setFieldWidth();
		try {


			while (more && cnt < 4) {
				if (cnt == 0) station_name = obj.extractToken(str, end, more);

				else if (cnt == 1) m_serialNum = std::stoi(obj.extractToken(str, end, more));

				else if (cnt == 2) m_numOfItem = std::stoi(obj.extractToken(str, end, more));

				else description = obj.extractToken(str, end, more);

				cnt++;
			}
		}
		catch (std::string err) {
			std::cout << "No Token Found";
		}




	}

	const std::string& Station::getItemName() const {
		return station_name;
	}
	//- returns the name of the current Station object

	unsigned int Station::getNextSerialNumber() {
		return m_serialNum++;
	}
	//– returns the next serial number to be used on the assembly line and increments m_serialNumber

	unsigned int Station::getQuantity() const {
		return m_numOfItem;
	}
	//– returns the remaining quantity of the current Station object

	void Station::updateQuantity() {
		if (getQuantity() > 0) {
			m_numOfItem -= 1;
		}

	}
	// – subtracts 1 from the available quantity; should not go below 0.

	void Station::display(std::ostream& os, bool full) const {
		if (full == false) {
			os << "[" << std::right << std::setw(3) << std::setfill('0');
			os << m_id << std::setfill(' ') << "] " << std::left;
			os << "Item: " << std::setw(12) << std::left << station_name << " [" << std::setw(6) << std::setfill('0')<<std::right << m_serialNum << "]" << std::setfill(' ') << std::endl;
		}
		else {
			os << "[" << std::right << std::setw(3) << std::setfill('0') << m_id << std::setfill(' ') << "] " << "Item: "<<std::left << std::setw(12) << station_name;
			os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNum << "] " << std::setfill(' ');
			os << "Quantity: " << std::setw(12) << std::left << m_numOfItem << " Description: " << description << std::endl;
		}

	}
	// --inserts the content of the current object into first parameter.



