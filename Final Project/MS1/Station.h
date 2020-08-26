#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
#include "Utilities.h"

namespace std {
	
	class Station {
		int m_id;                     //the id of a station(integer)
		std::string m_name;	         //the name of the item handled that the station(array of characters)
		std::string description;    //the description of the station(array of characters)
		unsigned int m_serialNum;           //the next serial number to be assigned to an item at this station(integer)
		unsigned int m_numOfItem;          //the number of current items left in stock(integer)
		
		
		
	public:
		static size_t m_widthField;
		static int id_generator;

		Station();

		Station(std::string& str);

		const std::string& getItemName() const;  // -returns the name of the current Station object

		unsigned int getNextSerialNumber();    // – returns the next serial number to be used on the assembly lineand increments m_serialNumber

		unsigned int getQuantity() const;    // – returns the remaining quantity of the current Station object

		void updateQuantity();             // – subtracts 1 from the available quantity; should not go below 0.

		void display(std::ostream& os, bool full) const;  // --inserts the content of the current object into first parameter.




	};

}
#endif