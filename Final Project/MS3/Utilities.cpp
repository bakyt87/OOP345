// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
#include "Utilities.h"
#include "Station.h"
using namespace std;


	char Utilities::m_delimiter = ',';


	Utilities::Utilities() {
		m_widthField = 1;
	}

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;

	}// --sets the field width of the current object to the value of the parameter
	size_t Utilities::getFieldWidth() const {
		return m_widthField;

	}// --returns the field width of the current object


	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		size_t pos = str.find(m_delimiter, next_pos);
		if (pos != next_pos) {
			more = (pos != std::string::npos) ? true : false;
			std::string token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
			if (token.size() > m_widthField)
			{
				m_widthField = token.length();
			}
			return token;
		}
		else
		{
			more = false;
			throw "No token found";

		}
	}
	/* --extracts tokens from the first parameter
	This function uses the delimiter to extract the next token from str starting at next_pos.
	If successful, it returns the extracted token found and sets more to true; false otherwise.
	This function reports an exception if there are two delimiters with no token between them.
	This function updates the current object's m_widthField data member if its current value is less than the size of the token extracted.*/
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	// --sets the delimiter for this class to the character received
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
	// --returns the delimiter character.
