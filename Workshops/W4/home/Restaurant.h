// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 10.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define  SDDS_RESTAURANT_H
#include<iostream>
#include "Reservation.h"
namespace sdds {
	class Restaurant{
		Reservation* array;
		size_t numOfRes;
	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
        Restaurant(Restaurant&& src);
		Restaurant& operator=(Restaurant&& src);
		virtual ~Restaurant();
		std::size_t size() const; // return how many reservations are in the system.
	         friend std::ostream& operator<<(std::ostream& os, const Restaurant& Ro);
		
	};
	
}
 






#endif