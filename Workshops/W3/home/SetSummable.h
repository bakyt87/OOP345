// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
#include "PairSummable.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream> 

namespace sdds {

        template <typename T, size_t N, typename K, typename V>
		class SetSummable : public Set<T, N> {
		public:
			

			V accumulate(const K& key) const {
				PairSummable<K, V>val;
				V accumulator = val.getInitialValue();
				
				for (size_t i = 0; i < this->size(); i++) {

					accumulator = (this->operator[](i)).sum(key, accumulator);

				}
				return accumulator;

			}
		};
}

#endif // !SDDS_SETSUMMABLE_H

