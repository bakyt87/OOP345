// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 10.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H 
#define  SDDS_CONFIRMATIONSENDER_H 
#include "Reservation.h"


namespace sdds {
	class ConfirmationSender{
	const Reservation** ptrArray;
	size_t sizeOfArray;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		virtual ~ConfirmationSender();
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		size_t size()const;
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& Ro);
    };
	
}
#endif




