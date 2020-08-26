// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <string>

#include "Workstation.h"
#include "Utilities.h"
using namespace std;

	Workstation::Workstation() :m_pNextStation{ nullptr } {}
	Workstation::Workstation(const std::string& oneLine) :Station(oneLine) {
		m_pNextStation = nullptr;
			}
	/*a custom constructor -- upon instantiation, a Workstation object receives
	a reference to an unmodifiable std::string. This string contains a single record 
	(one line) that has been retrieved from the input file specified by the user to be used 
	for Station instantiation.

this constructor will also set the m_pNextStation to a safe state.*/
	void Workstation::runProcess(std::ostream& os) {
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);
	}// runs a single cycle of the assembly line for the current station.
	//If there are CustomerOrders in the queue, this function fills the order
	//in the front at the current Workstation.
	bool Workstation::moveOrder() {
		bool res = false;
		if (!m_orders.empty() && m_orders.front().isItemFilled(getItemName()) && m_pNextStation) {
			res = true;
            *m_pNextStation += move(m_orders.front());
				m_orders.pop_front();
		}
		return res;
	}/*if the order at the front of the queue doesn't require service at the current station,
	 move it to the next station on the assembly line and return true. Otherwise, do nothing 
	 and return false. If the queue is empty, return false.*/
	void Workstation::setNextStation(Station& station) {
		m_pNextStation = (Workstation*)&station;
	}//stores the provided Station object's reference into the m_pNextStation pointer.

	const Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}//return the next station on the assembly line
	bool Workstation::getIfCompleted(CustomerOrder& order) {
		bool res = false;
		if (!m_orders.empty() && m_orders.front().isOrderFilled()) {
			order = move(m_orders.front());
			m_orders.pop_front();
			res = true;
		}
		return res;

	}/* if the order at the front of the queue is completed, this function removes from 
	 the queue, places it in the parameter and returns true; otherwise returns false.
	 If the CustomerOrder queue is empty, returns false.*/
	void Workstation::display(std::ostream& os) {
		if (getNextStation()) {
			os << getItemName() << " --> ";
			os << getNextStation()->getItemName() << endl;
		} else {
			os << getItemName() << " --> " << "END OF LINE" << endl;
		}
	}/* writes the name of the Item this Workstation is responsible for i
	 nto the parameter: ITEM_NAME --> NEXT_ITEM_NAME

if m_pNextWorkstation does not exist it writes: ITEM_NAME --> END OF LINE.
the messages are terminated with an endline*/
	Workstation& Workstation::operator+=(CustomerOrder&& param) {
		m_orders.push_back(move(param));
		return *this;
	}//moves the parameter onto the back of the CustomerOrder queue.
