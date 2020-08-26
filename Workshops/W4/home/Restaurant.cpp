// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 10.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <fstream>
#include<iostream>
#include <iomanip>
#include <string>
#include "Restaurant.h"
using namespace std;
namespace sdds {
	Restaurant::Restaurant() {
		array = nullptr;
		numOfRes = 0;
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		if (reservations != nullptr && cnt > 0) {
			numOfRes = cnt;
			array = new Reservation[cnt];
			for (size_t i = 0; i < cnt; i++) {
				array[i] = *reservations[i];
			}
		}
	}
	Restaurant::Restaurant(const Restaurant& src) {
		numOfRes = src.numOfRes;
		array = new Reservation[numOfRes];
		for (size_t i = 0; i < numOfRes; i++) {
			array[i] = src.array[i];
		}

	}
	Restaurant& Restaurant:: operator=(const Restaurant& src) {
		if (this != &src) {
			delete[] array;
			numOfRes = src.numOfRes;
			array = new Reservation[numOfRes];
			for (size_t i = 0; i < numOfRes; i++) {
				array[i] = src.array[i];
			}

		}
		return *this;
		
	}
	Restaurant::Restaurant(Restaurant&& src) {
		*this = move(src);
	}
	Restaurant& Restaurant:: operator=(Restaurant&& src) {
		if (this != &src) {
			numOfRes = src.numOfRes;
			array = src.array;
			src.numOfRes = 0;
			src.array = nullptr;

		}
		return *this;

	}
	Restaurant:: ~Restaurant() {
		delete[] array;
		array = nullptr;
	}
	size_t Restaurant::size() const {
		return numOfRes;// return how many reservations are in the system.
	}
	
        std::ostream& operator<<(std::ostream& os,const Restaurant& Ro) {
			if (Ro.numOfRes == 0 && Ro.array == nullptr) {
				os << "--------------------------" << endl;
				os << "Fancy Restaurant" << endl;
				os << "--------------------------" << endl;
				os << "The object is empty!" << endl;
				os << "--------------------------" << endl;
			}else{
				os << "--------------------------" << endl;
				os << "Fancy Restaurant" << endl;
				os << "--------------------------" << endl;
				for (size_t i = 0; i < Ro.size(); i++) {
					os << Ro.array[i];
				}
					
				os << "--------------------------" << endl;
            
			}
                return os;
		}
}