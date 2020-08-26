// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include "SpellChecker.h"
 
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {

		std::ifstream file(filename);
		std::string err = "Bad file name!";
		if (!file) {
			throw err;
		}
		else if (file) {
			for(size_t i=0;i<size && file;i++){
				std::string str;
				std::getline(file, str);
				
				m_badwords[i] = str.substr(0,str.find(" "));
				str.erase(0, str.find_last_of(" ") + 1);
				str.erase(remove(str.begin(), str.end(), '\n'), str.end());
				str.erase(remove(str.begin(), str.end(), '\r'), str.end());
				m_goodwords[i] = str;

			}
		}
	}
	void SpellChecker::operator()(std::string& text) const {
		//std::string str;
		for (int i = 0; i < size; i++){
			while (text.find(m_badwords[i]) != std::string::npos) {
				
				text.replace(text.find(m_badwords[i]), m_badwords[i].length(), m_goodwords[i]);

			}

		}


	}
}