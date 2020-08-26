// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 13.02.2020
//
// I confirm that the content of this file is partially created by me,
//   with the exception of the parts provided to me by my professor.
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		std::ifstream file(argv[1]);
		if (file.good()) {
			std::string temp;
			int cnt = 0;
			for (std::string temp; std::getline(file, temp);) {
				if (temp.at(0) != '#') {
					library[cnt] = Book(temp);
					cnt++;
				}
			}


		}

		double usdToCadRate = 1.3;
		double gbpToCadRate = 1.5;

		// TODO: create a lambda expression that fixes the price of a book accoding to the rules
		//       - the expression should receive a single parameter of type "Book&"
		//       - if the book was published in US, multiply the price with "usdToCadRate"
		//            and save the new price in the book object
		//       - if the book was published in UK between 1990 and 1999 (inclussive),
		//            multiply the price with "gbpToCadRate" and save the new price in the book object
		auto priceFix = [=](Book& param) {
			if (param.country().compare("US") == 0)
			{
				param.price() *= usdToCadRate;
			}
			if ((param.country().compare("UK") == 0) && (param.year() >= 1990 && param.year() <= 1999)) {
				param.price() *= gbpToCadRate;
			}

		};

		std::cout << "-----------------------------------------\n";
		std::cout << "The library content\n";
		std::cout << "-----------------------------------------\n";
		for (auto& book : library)
			std::cout << book;
		std::cout << "-----------------------------------------\n\n";

		// TODO: iterate over the library and update the price of each book
		//         using the lambda defined above.
		for (int i = 0; i < 7; i++) {
			priceFix(library[i]);
		}


		std::cout << "-----------------------------------------\n";
		std::cout << "The library content (updated prices)\n";
		std::cout << "-----------------------------------------\n";
		for (auto& book : library)
			std::cout << book;
		std::cout << "-----------------------------------------\n";

		return 0;
	}
}
