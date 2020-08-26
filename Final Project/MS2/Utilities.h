#pragma once
#ifndef STD_UTILITIES_H
#define STD_UTILITIES_H
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>

namespace std {
	class Utilities {
		size_t m_widthField{1};//-- specifying the length of the token extracted; used for display purpose later; default value is 1.
		static char m_delimiter; // --separates the tokens from a given std::string.All Utilities objects share the same delimiter.
	public:
		Utilities();
		void setFieldWidth(size_t newWidth);// --sets the field width of the current object to the value of the parameter
		size_t getFieldWidth() const;// --returns the field width of the current object
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more); /* --extracts tokens from the first parameter
			This function uses the delimiter to extract the next token from str starting at next_pos.
			If successful, it returns the extracted token found and sets more to true; false otherwise.
			This function reports an exception if there are two delimiters with no token between them.
			This function updates the current object's m_widthField data member if its current value is less than the size of the token extracted.*/
		static void setDelimiter(char newDelimiter); // --sets the delimiter for this class to the character received
		static char getDelimiter(); // --returns the delimiter character.
	};
}



#endif