// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 

#include <iostream>
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"


//using namespace std;
namespace sdds {


	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		endTime= std::chrono::steady_clock::now();
	}
	void TimedEvents::recordEvent(const char*name) {
		auto eventDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

		if (numOfRecords < MAX) {
			this->event[numOfRecords].unitsOfTime = "nanoseconds";
			this->event[numOfRecords].duration = eventDuration;
			this->event[numOfRecords].eventName = name;
			numOfRecords++;

        }

	}
	std::ostream& operator<<(std::ostream& os, const TimedEvents& object) {
		os << "--------------------------\n";
		os << "Execution Times:\n";
		os << "--------------------------\n";
		for (int i = 0; i < object.numOfRecords; i++) {
		os<<std::setw(20)<<std::left<<
		 object.event[i].eventName << " " <<std::setw(12)<<std::right
			<< object.event[i].duration.count() << " " 
			<< object.event[i].unitsOfTime << '\n';

		}
		os << "--------------------------\n";
		return os;
	}
     }