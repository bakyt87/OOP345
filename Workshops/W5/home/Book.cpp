// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

	#include <fstream>
	#include <iostream>
	#include <string>
    #include <iomanip>
    #include "Book.h"
using namespace std;
	namespace sdds {
		Book::Book() {
		
		 m_author="";
		 m_title = "";
	     m_country = "";
		 m_description = "";
		 m_year=0;
		 m_price=0;

		}
		const std::string& Book::title() const {
			return m_title;
		}                                        // : a query that returns the title of the book
		const std::string& Book::country() const {
			return m_country;
		}                                        // : a query that returns the publication country
		const size_t& Book::year() const {
			return m_year;
		}                                        // : a query that returns the publication year
		double& Book::price() {
			return m_price;
		}                                      // : a function that returns the price by reference, allowing you to update the price
		Book::Book(const std::string& strBook) {
			size_t start = 0;
			size_t end = 0;
			end = strBook.find(",");
			trim(m_author = strBook.substr(start, end - start));

			start = end + 1;
			end = strBook.find(",", start);
			trim(m_title = strBook.substr(start, end - start));

			start = end + 1;
			end = strBook.find(",", start);
			trim(m_country = strBook.substr(start, end - start));

			start = end + 1;
			end = strBook.find(",", start);
			m_price = stod(strBook.substr(start, end - start));

			start = end + 1;
			end = strBook.find(",", start);
			m_year = stoi(strBook.substr(start, end - start));

			start = end + 1;
			end = strBook.find(".", start);
			trim(m_description = strBook.substr(start, end - start));
		}            // : A constructor that receives the book as a string; this constructor is
		//responsible to extract the information about the book from the parameterand store it in the attributes
		//of the instance.The parameter will always have the following format :
		void Book::trim(std::string& string) {
			size_t i;
			for (i = 0; i < string.length() && string[i] == ' '; i++);

			string = string.substr(i);

			for (i = string.length(); i > 0 && string[i - 1] == ' '; i--);

			string = string.substr(0, i);
        }							   // AUTHOR, TITLE, COUNTRY, PRICE, YEAR, DESCRIPTION*/

		std::ostream& operator<<(std::ostream& os, const Book& rhs) {
			os << std::setw(20);
			os << rhs.m_author << " | ";
			os << std::setw(22);
			os << rhs.title() << " | ";
			os << std::setw(5);
			os << rhs.country() << " | ";
			os << std::setw(4);
			os << rhs.year() << " | ";
			os << std::setw(6) <<fixed<<setprecision(2)<< rhs.m_price<<endl;

			return os;
		}
    }

	
	 /*the author should be printed on a field of size 20;
     the title should be printed on a field of size 22;
     the country should be printed on a field of size 5;
     the year should be printed on a field of size 4;
     the price should be printed on a field of size 6, and should have 2 digits;
     see alignment in the sample output.*/