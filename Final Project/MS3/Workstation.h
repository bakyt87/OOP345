
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include <numeric>
#include "Station.h"
#include "CustomerOrder.h"
#include "Station.h"
using namespace std;

	class Workstation :public Station {
		deque <CustomerOrder>m_orders;
		Workstation* m_pNextStation{};
	public:
		Workstation();
		Workstation(const std::string&);
		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		void runProcess(std::ostream&); // runs a single cycle of the assembly line for the current station.
		//If there are CustomerOrders in the queue, this function fills the order in the front at the current Workstation.
		bool moveOrder();
		void setNextStation(Station& station);
		const Workstation* getNextStation() const;
		bool getIfCompleted(CustomerOrder& order);
		void display(std::ostream& os=cout);
		Workstation& operator+=(CustomerOrder&& param);
	};




#endif