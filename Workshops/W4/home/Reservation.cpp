// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 07 February 2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Reservation.h"
using namespace std;
namespace sdds {

	Reservation::Reservation() {
		resId = ""; // reservation id : an array of characters
		name = "";  // the name on the reservation
	    email = ""; // the email that can be used to send the confirmation that the reservation can be honored or not
	    number = 0; //	the number of people in the party
		partyDay = 0; //	the day when the party is expected to come(for simplicity, the day is an integer between 1 and 31)
		partyHour = 0; //	the hour when the party is expected to come(for simplicity, the hour is an integer between 1 and 24)
	}
	Reservation::Reservation(const std::string& res) {
		
		size_t start = 0;
		size_t end = 0;
		end = res.find(":");
		trim(resId = res.substr(start, end - start));

		start = end + 1;
		end = res.find(",", start);
		trim(name = res.substr(start, end - start));

		start = end + 1;
		end = res.find(",", start);
		trim(email = res.substr(start, end - start));

		start = end + 1;
		end = res.find(",", start);
		number = stoi(res.substr(start, end - start));

		start = end + 1;
		end = res.find(",", start);
		partyDay = stoi(res.substr(start, end - start));

		start = end + 1;
		partyHour = stoi(res.substr(start));

	}
	void Reservation::trim(std::string& string) {
		size_t i;
		for (i = 0; i < string.length() && string[i] == ' '; i++);
			
		string = string.substr(i);
		
			for (i = string.length(); i > 0 && string[i - 1] == ' '; i--);
				
			string = string.substr(0, i);
			
		
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& Ro) {
		os << "Reservation " << Ro.resId << ": ";
		os << std::setw(10) << std::right << Ro.name;
		os << " ";
		os << std::setw(20) << std::left << " <"+ Ro.email+">";
		os << "    ";
		if (Ro.partyHour >= 6 && Ro.partyHour <= 9) {
         
			os << " Breakfast ";
		}
		else if (Ro.partyHour >= 11 && Ro.partyHour <= 15) {

			os << " Lunch ";
		}
		else if (Ro.partyHour >= 17 && Ro.partyHour <= 21) {

			os << " Dinner ";
		}
		else {
			os << " Drinks "; 
		}
		os << "on day " << Ro.partyDay << " @ " << Ro.partyHour << ":00 for " << Ro.number << " people." << endl;
		return os;
	}
}
	





