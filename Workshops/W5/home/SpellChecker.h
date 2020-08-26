// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
namespace sdds {
	class SpellChecker {
		std::string m_badwords[5];
		std::string m_goodwords[5];
		static const int size = 5;
		
	public:
		SpellChecker(const char* filename);
		/* a constructor that receives as a parameter the
									   name of the file that contains the misspelled words. 
										   If the file is missing, this constructor should generate an 
										   exception of type const char*, with the message Bad file name!

this constructor should load the content of the file. Each line from the file is in the
format BAD_WORD GOOD_WORD; the two fields can be separated by any number of spaces.*/
		void operator()(std::string& text) const;
    };
}


#endif // !SDDS_SPELLCHECKER_H

