
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace std {

	size_t Station:: m_widthField = 0;
	int Station:: id_generator = 1;
	
	Station::Station() {
		
		m_id = 001;             //the id of a station(integer)
		m_name = "";	       //the name of the item handled that the station(array of characters)
		description = "";     //the description of the station(array of characters)
		m_serialNum = 0;     //the next serial number to be assigned to an item at this station(integer)
		m_numOfItem = 0;    //the number of current items left in stock(integer)
	}
	Station::Station(std::string& str) {
		bool more = true;
		size_t end = 0;
		size_t cnt = 0;
        Utilities obj; // used to extract tokens
		m_id =id_generator;
		id_generator++;
		
		
		//obj.setFieldWidth();
		try {  


			while (more && cnt < 4) {
				if (cnt == 0) m_name = obj.extractToken(str, end, more);

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
		return m_name;
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
			os << "[" <<std::right<< std::setw(3) << std::setfill('0') << m_id << std::setfill(' ') << "] ";
			os << "Item: " <<std::setw(12)<<std::left<< m_name <<" [" <<std::right<< std::setw(6) << std::setfill('0')<< m_serialNum << "]"<< std::setfill(' ')<<std::endl;
		}
		else {
			os << "[" <<std::right<< std::setw(3) << std::setfill('0') << m_id << std::setfill(' ') << "] " << "Item: " << std::setw(12)<<std::left << m_name;
			os << " ["<<std::right << std::setw(6) << std::setfill('0') << m_serialNum << "] "<<std::setfill(' ');
			os << "Quantity: " << std::setw(12)<<std::left<< m_numOfItem << " Description: " << description << std::endl;
		}
		
		}
		// --inserts the content of the current object into first parameter.



}