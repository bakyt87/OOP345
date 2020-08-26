// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 
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
		S = nullptr;
		*this = src;
	}
	RecordSet& RecordSet:: operator=(const RecordSet& src) {
		if (this != &src) {
			this->numOfStr = src.numOfStr;
			delete [] this->S;
			this->S = new string[numOfStr];

			for (long unsigned int i = 0; i < numOfStr; i++) {
				this->S[i] = src.S[i];
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
	RecordSet::RecordSet(RecordSet&& src) {
                S =nullptr;
		*this = std::move(src);
	}
	RecordSet& RecordSet::operator=(RecordSet&& src) {
		if (this != &src) {
			numOfStr = src.numOfStr;
			delete [] S;
			S = src.S;
			src.S = nullptr;
			src.numOfStr = 0;
        }
		return *this;
	}
}

