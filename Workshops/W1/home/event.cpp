// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
	
#define _CRT_SECURE_NO_WARNINGS
	#include <iostream>
	#include <iomanip>
	#include <fstream>
	#include "event.h"
	#include <cstring>


	using namespace std;
	namespace sdds {

	
		Event::Event() {
			m_event=nullptr;
			m_startTime = 0;
		}
	
		Event::Event(const Event& cString) {
			if (cString.m_event != nullptr) {
				m_startTime = cString.m_startTime;

				m_event = new char[strlen(cString.m_event) + 1];
				strcpy(m_event, cString.m_event);
			
			}
	
		}
			Event& Event:: operator=(const Event& src) {
				if (this != &src) {
					m_startTime = src.m_startTime;
					delete[] m_event;
					m_event = new char[strlen(src.m_event) + 1];
					strcpy(m_event, src.m_event);
				}
				else {
					m_event = nullptr;
				}
				return *this;
			}
		Event:: ~Event() {

			delete [] m_event;
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
		void Event::setDescription(char* description )  {

		

			if (description !=nullptr) {
			
				m_event = new char[strlen(description) + 1];

				strcpy(m_event, description);


				m_startTime = g_sysClock;
			}
			else {
				m_event = new char[strlen("[ No Event ]")+1];
				strcpy(m_event, "[ No Event ]");
		
			}
		}
	



	}