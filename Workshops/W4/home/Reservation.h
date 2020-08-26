// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 07 February 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef  SDDS_RESERVATION_H
#define  SDDS_RESERVATION_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
namespace sdds {
	class Reservation {
		std::string resId; // reservation id : an array of characters
		std::string name; // the name on the reservation
		std::string email; // the email that can be used to send the confirmation that the reservation can be honored or not
		int number; //	the number of people in the party
		int partyDay; //	the day when the party is expected to come(for simplicity, the day is an integer between 1 and 31)
		int partyHour; //	the hour when the party is expected to come(for simplicity, the hour is an integer between 1 and 24)
	public:
		Reservation();
		Reservation(const std::string&);
		void trim(std::string&);
		friend std::ostream& operator<<(std::ostream& os, const Reservation&);

	};
}
#endif // ! SDDS_RESERVATION_H

