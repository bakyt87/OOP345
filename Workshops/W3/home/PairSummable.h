// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include "Pair.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream> 

namespace sdds {

	template<typename K, typename V>
	class PairSummable :public Pair<K,V>{
		static V initialValue;
		static size_t minimumNum;
	public:
		static const V& getInitialValue() {
			
			return initialValue;
		}
		PairSummable() :Pair<K,V>() {}
		
		PairSummable(const K& key, const V& value) :Pair<K, V>(key, value){
			if (minimumNum < key.size()) {
				
				minimumNum = key.size();
				}
		}
			V sum(const K& key, const V& val)const {
			
			V a;

			if (this->key() == key) {
				a = this->value() + val;

			}
			else {
				a = val;
			}
			return a;

		}
			void display(std::ostream& os) const {
				os << std::left << std::setw(minimumNum);
				Pair<K, V>::display(os);
				os << std::right;

			}


    };
	template<>
	std::string PairSummable<std::string, std::string>::initialValue = "";

	template<typename K, typename V>
	V PairSummable<K, V>::initialValue = 0;

	template<typename K, typename V>
	size_t PairSummable<K, V>::minimumNum = 0;
	
	template<>
	std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& val) const {

		std::string result;

		if (this->key() == key) {
			if (val == "") {
				result = this->value();
			}
			else {
				result = val + ", " + this->value();
			}
		}
		else {
			result = val;
		}
		return result;
    }
}





#endif // !SSDS_PAIRSUMMABLE_H
