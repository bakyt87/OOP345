
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>

namespace sdds {

class Movie{
	std::string movie_title;
	std::string movie_descrip;
	size_t movie_year;
public:
	Movie();                                //a default constructor
	const std::string& title() const;      // : a query that returns the title of the movie
	Movie(const std::string& strMovie);   //  : A constructor that receives the movie as a string;
	//this constructor is responsible to extract the information about the movie from the parameterand
		//store it in the attributes of the instance.The parameter will always have the following format :
	void trim(std::string& string);
	friend std::ostream& operator<<(std::ostream& os, const Movie&);
	template <typename T> 
	void fixSpelling(T spellChecker) {
		spellChecker(movie_title);
		spellChecker(movie_descrip);
	}// a template function.This function should call the overloaded operator() 
	//on instance spellChecker, passing to it the movie title and description.
   //In this design, type T must have an overload of the operator() that accepts a string as a parameter.
	
   };
    

}
#endif