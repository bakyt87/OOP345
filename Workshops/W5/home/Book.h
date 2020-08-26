// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>

namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		size_t m_year;
		double m_price;
	public:
		Book();
		const std::string& title() const; // : a query that returns the title of the book
		const std::string& country() const; // : a query that returns the publication country
		const size_t& year() const; // : a query that returns the publication year
		double& price(); // : a function that returns the price by reference, allowing you to update the price
		Book(const std::string& strBook); // : A constructor that receives the book as a string; this constructor is responsible to extract the information about the book from the parameterand store it in the attributes of the instance.The parameter will always have the following format :
		void trim(std::string& string);                              // AUTHOR, TITLE, COUNTRY, PRICE, YEAR, DESCRIPTION*/
		friend std::ostream& operator<<(std::ostream& os, const Book&);
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
			
			// this function should call the overloaded operator() on instance
		//spellChecker, passing to it the book description.

			//In this design, type T must have an overload of the operator() that accepts a string as a parameter.

			//Since this is a template function, it must be implemented in the header!The class is not a template.
	};
}



	




#endif