// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 24.01.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <string>
#include "RecordSet.h"

using namespace std;
namespace sdds {


	RecordSet::RecordSet() {
		S = nullptr;
		numOfStr = 0;

	}
	RecordSet::RecordSet(const char* name) {
		ifstream file(name);
		int spaces = 0;
		string store;
		if (file.is_open()) 
		{
			while (!file.eof() && file.good())
			{
				getline(file, store, ' ');
				store.clear();
				spaces++;

			}
			numOfStr = spaces;
			if (file.eof()) 
			{
                        	file.clear();
				file.seekg(0, file.beg);
			}
				S = new string[spaces];
				int num = 0;
				while (!file.eof() && file.good())
				{
					getline(file, S[num], ' ');
					num++;
				}
			

		}
	}
	RecordSet::RecordSet(const RecordSet& src) {
		if (src.S != nullptr) {
			this->numOfStr = src.numOfStr;
			this->S = new string[numOfStr];

			for (long unsigned int i = 0; i < numOfStr; i++) {
				this->S[i] = src.S[i];
			}
		}
	}
	RecordSet& RecordSet:: operator=(const RecordSet& og) {
		if (this != &og) {
			this->numOfStr = og.numOfStr;
			delete [] this->S;
			this->S = new string[numOfStr];

			for (long unsigned int i = 0; i < numOfStr; i++) {
				this->S[i] = og.S[i];
			}
	
		}
		else {
			S = nullptr;
		}
		return *this;
	}
	RecordSet::~RecordSet() {
		delete [] this->S;
	}
	size_t RecordSet::size() {
		return numOfStr;
	}
	std::string RecordSet::getRecord(size_t size) {

		return size < numOfStr ? S[size] : "";
	}
}

