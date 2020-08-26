// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 17.03.2020
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
		m_price = 0;
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
				m_price = stod(str.substr(85, 5));
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

	SongCollection::~SongCollection() {}

	void SongCollection::display(std::ostream& out) const {

		std::for_each(vec.begin(), vec.end(), [&](const Song song) {out << song << std::endl; });
		out << "----------------------------------------------------------------------------------------" << std::endl;
		out << "|";
		out << "                                                        Total Listening Time: ";
		auto totalLength = [](int sec) {
			std::string length;
			int hour;
			int min;
			min = sec / 60;
			hour = min / 60;
			length += std::to_string(hour);
			length += ":";
			length += int(min % 60) < 10 ? std::string("0") + std::to_string(int(min % 60)) : std::to_string(int(min % 60));
			length += ":";
			length += int(sec % 60) < 10 ? std::string("0") + std::to_string(int(sec % 60)) : std::to_string(int(sec % 60));
			return length;		};
		out << totalLength(std::accumulate(vec.begin(), vec.end(), (int)0, [](int sum, const Song song) {return sum + song.songLength; }));
        out<< " |" << std::endl;
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
		out << std::setprecision(2) << std::fixed << theSong.m_price;
		out << " |";
		return out;
	}
	void SongCollection::sort(std::string field_name) {
		auto sortVec = [field_name](Song song, Song m_song) {

			std::string str(field_name);

			if (field_name == std::string("title"))
				return song.title < m_song.title;
			else if (str == std::string("album"))
				return song.album < m_song.album;
			else if (str == std::string("length"))
				return song.songLength < m_song.songLength;
			else
				throw "Invalid Fieldname ";
		};
		std::sort(vec.begin(), vec.end(), sortVec);
	}               //receives as a parameter the name of the field used to sort the collection of songs in ascending order.
	                     //The parameter can have one of the values title, album, or length.DO NOT USE MANUAL LOOPS!
	  
	void SongCollection::cleanAlbum() {
		auto clean = [](Song& song) {
			if (song.album == std::string("[None]"))
				song.album.clear();
		};
		std::for_each(vec.begin(), vec.end(), clean);
	}//removes the token[None] from the album field of the songs that do not have a valid album.DO NOT USE MANUAL LOOPS!

	bool SongCollection::inCollection(std::string name)const {
		
		return std::any_of(vec.begin(), vec.end(), [name](const Song& song) {
			return song.artist == std::string(name);
			});
	}//receives the name of an artist as a parameter, and returns true if the collection contains any song by that artist.DO NOT USE MANUAL LOOPS!

	std::list<Song> SongCollection:: getSongsForArtist(const char* name) const {
		std::list<Song>artist_list(vec.size());
		auto iterator = std::copy_if(vec.begin(), vec.end(), artist_list.begin(), [name](const Song& song) {
		return song.artist == std::string(name); });
		artist_list.resize(std::distance(artist_list.begin(), iterator));
		return artist_list;

	}
  //receives the name of an artist as a parameter, and returns the the list of songs of that artist available in the collection.DO NOT USE MANUAL LOOPS!

	unsigned long operator+(unsigned long total_time, const Song& song) {
		return total_time + song.songLength;
	}
	std::string Song::operator=(const std::string& _album) {
		return album = _album;
	}
}
