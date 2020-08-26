// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 31.01.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <fstream> 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

namespace sdds {
	template < typename K, typename V>
	class Pair {
		K m_key;
		V m_value;
	public:
		Pair() {}
		
		Pair(const K& key, const V& value) {
			m_key = key;
			m_value = value;

		}
		const K& key() const {
			return m_key;
		}
		const V& value() const {
			return m_value;
		}
		virtual void display(std::ostream& os) const {
			os << m_key << " : " << m_value << std::endl;
		}
		
        };
		template < typename K, typename V> 
		std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
			pair.display(os);
			return os;
		}


	
}

#endif
