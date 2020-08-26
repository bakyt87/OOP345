// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include<iomanip>
#include"Movie.h"

namespace sdds{ 
	Movie::Movie() {
		movie_title = "";
		movie_descrip = "";
		movie_year = 0;//a default constructor
	}
	const std::string& Movie::title() const {
		return movie_title;// : a query that returns the title of the movie
	}
	Movie::Movie(const std::string& strMovie) {
		size_t start = 0;
		size_t end = 0;
		end = strMovie.find(",");
		trim(movie_title = strMovie.substr(start, end - start));
		
		start = end + 1;
		end = strMovie.find(",", start);
		movie_year = stoi(strMovie.substr(start, end - start));

		start = end + 1;
		end = strMovie.find(".",start);
		trim(movie_descrip = strMovie.substr(start, end - start));
	}
	
	void Movie::trim(std::string& string) {
		size_t i;
		for (i = 0; i < string.length() && string[i] == ' '; i++);

		string = string.substr(i);

		for (i = string.length(); i > 0 && string[i - 1] == ' '; i--);

		string = string.substr(0, i);
	}
	std::ostream& operator<<(std::ostream& os, const Movie& rhs) {
		os << std::setw(40);
		os << rhs.title() << " | ";
		os << std::setw(4);
		os << rhs.movie_year << " | ";
		
		os << rhs.movie_descrip;
		return os;
	}
}
