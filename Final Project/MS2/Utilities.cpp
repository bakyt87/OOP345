
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
#include "Utilities.h"
#include "Station.h"

namespace std {

	char Utilities::m_delimiter = ' ';


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
		std::string err;
		std::string temp = str.substr(next_pos);
		size_t end = temp.find(m_delimiter);
		if (end != std::string::npos) {
			temp = temp.substr(0, end);
			if (temp.size() > m_widthField) {

				m_widthField = temp.size();

			}
			next_pos += end + 1;
			if (next_pos < str.size() && str[next_pos] == m_delimiter) {
				throw err;
			}
			more = true;

		}
		else {
			more = false;
		}
		return temp;

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
}