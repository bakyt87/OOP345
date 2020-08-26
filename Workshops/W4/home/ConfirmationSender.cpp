// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 10.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "ConfirmationSender.h"
using namespace std;
namespace sdds{


ConfirmationSender::ConfirmationSender() {
	ptrArray = nullptr;
	sizeOfArray = 0;
}
ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
	if (src.ptrArray != nullptr && src.sizeOfArray != 0) {
		sizeOfArray = src.sizeOfArray;
		ptrArray = new const Reservation* [sizeOfArray];
		for (size_t i = 0; i < sizeOfArray; i++) {
			ptrArray[i] = src.ptrArray[i];
		}
	}
}
	ConfirmationSender& ConfirmationSender:: operator=(const ConfirmationSender & src) {
		if (this != &src) {
			delete[] ptrArray;
			sizeOfArray = src.sizeOfArray;
		for (size_t i = 0; i < sizeOfArray; i++) {
				ptrArray[i] = src.ptrArray[i];
			}
		}
		return *this;
}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		*this = move(src);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (this != &src) {
			ptrArray = src.ptrArray;
			sizeOfArray = src.sizeOfArray;
			src.ptrArray = nullptr;
			src.sizeOfArray = 0;
		}
		return *this;
	
	}
   ConfirmationSender:: ~ConfirmationSender() {
	delete[] ptrArray;
	ptrArray = nullptr;
}
   size_t ConfirmationSender::size() const {
	   return sizeOfArray;
   }
   ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
	   bool ok = false;
	   for (size_t i = 0; i < sizeOfArray; i++) {
		   if (ptrArray[i] == &res) {
                   ok=true;
                   break;
            }
            }
            if(ok==false){
                  if(ptrArray==nullptr){
			   ptrArray = new const Reservation * [sizeOfArray + 1];
			   ptrArray[sizeOfArray] = &res;
			   sizeOfArray += 1;
		   }
		   else {
			   const Reservation** temp = new const Reservation * [sizeOfArray + 1];
			   for (size_t i = 0; i < sizeOfArray; i++) {
				   temp[i] = ptrArray[i];
               }
			   temp[sizeOfArray] = &res;
			   sizeOfArray += 1;
			   delete[] ptrArray;
			   ptrArray = temp;
		   }
	   }
	   return *this;
}
ConfirmationSender& ConfirmationSender:: operator-=(const Reservation& res) {
	for (size_t i = 0; i < sizeOfArray; i++) {
		if (ptrArray[i] == &res) {
			ptrArray[i] = nullptr;
			sizeOfArray -= 1;
		}
	}
	return *this;
}

        std::ostream& operator<<(std::ostream& os, const ConfirmationSender& Ro) {
	if (Ro.sizeOfArray == 0 && Ro.ptrArray == nullptr) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		os << "The object is empty!" << endl;
		os << "--------------------------" << endl;
	}else{
		
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		for (size_t i = 0; i < Ro.sizeOfArray; i++) {
			
		os << *Ro.ptrArray[i];
		
			}
		os << "--------------------------" << endl;
	}
        return os;
        }
}

