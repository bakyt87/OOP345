// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 13.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#pragma once
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>

namespace sdds
{

	struct Song{
	
	std::string artist;
	std::string title;
	std::string album;
	double price;
	std::string releaseYear;
    size_t songLength;
	Song();
	Song(const std::string& str);
	
	};

	class SongCollection {
		std::vector<Song>vec;
		unsigned int collection;
	public:
		SongCollection();
		SongCollection(const char* text);
		void display(std::ostream& out) const;
    };
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	

}



#endif // !SDDS_SONGCOLLECTION_H
