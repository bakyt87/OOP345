#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "event.h"
#include <cstring>


using namespace std;
namespace sdds {

	
	Event::Event(): m_event(""){
		//m_event[0] ='/0';
		m_startTime = 0;
	}
	

	void Event::display() {
		unsigned int seconds, minutes, hour;
		static int COUNTER=1;
		seconds = 0u;
		minutes = 0u;
		hour = 0u;
		 
		
		cout << setw(3) << setfill(' ') << COUNTER++ << ". ";
			
			minutes = m_startTime / 60;
			seconds = m_startTime % 60;
			hour = minutes / 60;
			minutes = minutes % 60;
		
		
			if (strcmp(m_event,"[ No Event ]")!=0) {
			

				cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " -> ";
				
			}
			
			cout << m_event << endl;
			
}
	void Event::setDescription(char* description) {

		

		if (description !=nullptr) {
			
			strncpy(m_event, description, 127);

			m_startTime = g_sysClock;
		}
		else {
			strcpy(m_event, "[ No Event ]");
		
		}
	}
	



}