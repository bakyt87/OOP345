// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 31.01.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	template <typename T, size_t N>
	class Set {
		T array[N];
		size_t numElements = 0;
	public:
		size_t size() const {
			return numElements;
		}
		const T& operator[](size_t idx) const {
			return array[idx];
		}
		void operator+=(const T& item) {
			if (numElements < N) {
				array[numElements] = item;
				numElements++;
			}
		}


	};

}

#endif
