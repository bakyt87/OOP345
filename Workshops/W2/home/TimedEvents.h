 

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <iomanip>
#include <chrono>
namespace sdds {

const int MAX=7;
	class TimedEvents {

	    int numOfRecords=0;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct {
			std::string eventName;
			std::string unitsOfTime;
			std::chrono::steady_clock::time_point::duration duration;
		} event[MAX];
	public:
		
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& object);



};

	


}
#endif // !SDDS_TIMEDEVENTS_H

