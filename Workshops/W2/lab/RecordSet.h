
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 24.01.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <chrono>
#include <fstream>
#include <cstring>


namespace sdds {
	class RecordSet {
		long unsigned int numOfStr;
		std::string *S;
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet& copy);
		RecordSet& operator=(const RecordSet& assign);
		virtual ~RecordSet();
		size_t size();
		std::string getRecord(size_t);
	};
}

#endif // !SSD_RECORDSET_H

