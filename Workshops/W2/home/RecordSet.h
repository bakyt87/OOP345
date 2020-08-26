
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <chrono>
#include <fstream>
#include <string>


namespace sdds {
	class RecordSet {
		long unsigned int numOfStr;
		std::string *S;
	public:
		RecordSet();
		RecordSet(const char*);
		RecordSet(const RecordSet&);
		RecordSet& operator=(const RecordSet&);
		virtual ~RecordSet();
		size_t size();
		std::string getRecord(size_t);
		RecordSet(RecordSet&&);
		RecordSet& operator=(RecordSet&&);
	};
}

#endif // !SSD_RECORDSET_H

