// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 13.03.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <string>
#include "SongCollection.h"

namespace sdds {
	Song::Song() {
		artist = "";
		title = "";
		album = "";
		releaseYear = "";
		price = 0;
		songLength = 0u;

	}
	Song::Song(const std::string& str): Song() {
		std::string length;

		auto trim = [](std::string txt) { 
			
			if ((!txt.empty() && !std::all_of(txt.begin(), txt.end(), isspace))) {

				while (txt.at(0) == ' ')
					txt = txt.substr(1, txt.length() - 1);

				while (txt.at(txt.length() - 1) == ' ')
					txt = txt.substr(0, txt.length() - 1);
			}
			return txt;
		};
		
		if (!str.empty() && str.length() >= 90) {

			title = trim((str.substr(0, 24)));

			artist = trim(str.substr(24, 25));

			album = trim(str.substr(50, 25));

			releaseYear = trim(str.substr(75, 5));

			songLength = stoul(trim(str.substr(80, 5)));
			try {
				price = stod(str.substr(85, 5));
			}
			catch (...) {
				throw "Price is not a number";
			}
		}
	}
	SongCollection::SongCollection() {
		collection = 0;
	}
	
	SongCollection::SongCollection(const char* text): SongCollection(){
		std::ifstream file(text);
		std::string line;
		if (std::string(text) == std::string("songs.txt")) {
			if (file.good()) {

				while (std::getline(file, line))
				if (!line.empty()) {
					Song temp(line);
					vec.push_back(temp);
					collection += vec.back().songLength;
				}
			}
		}
		else
		{
			throw std::string("Wrong file");
		}
		file.close();
	}

	void SongCollection::display(std::ostream& out) const {
		std::for_each(vec.begin(), vec.end(), [&](const Song song) {out << song << std::endl; });
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		auto songLengthTime = [](int sec) {
			std::string length;
			int min;
			min = sec / 60;
			length += std::to_string(int(min % 60));
			length += ":";
			length += int(sec % 60) < 10 ? "0" + std::to_string(int(sec % 60)) : std::to_string(int(sec % 60));
			return length;
		};
		out << "| ";
		out << std::left << std::setw(20) << theSong.title;
		out << " | ";
		out << std::left << std::setw(15) << theSong.artist;
		out << " | ";
		out << std::left << std::setw(20) << theSong.album;
		out << " | ";
		out << std::right << std::setw(6) << theSong.releaseYear;
		
		out << " | ";
		out << songLengthTime(theSong.songLength);
		out << " | ";
		out << std::setprecision(2) << std::fixed << theSong.price;
		out << " |";
		return out;
	}

}
