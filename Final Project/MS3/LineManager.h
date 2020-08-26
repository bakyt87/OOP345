// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef STD_LINEMANAGER_H
#define STD_LINEMANAGER_H
#include <deque>
#include <vector>
#include <string>
#include "Workstation.h"
#include "Utilities.h"
using namespace std;


	class LineManager {
		//A LineManager object manages the entire assembly lineand contains the following information :

		vector<Workstation*> AssemblyLine; // – A container containing all the references of the Workstation objects on the assembly line
		vector<Workstation*> Sorted_AssemblyLine;
		deque<CustomerOrder> ToBeFilled; // – A queue of customer orders to be filled
		deque<CustomerOrder> Completed; // – A queue of customer orders completed
		unsigned int m_cntCustomerOrder; // – The number of CustomerOrder objects the assembly line started with.
		static size_t count;
	public:
			LineManager();
		//custom constructor
			LineManager(string str, vector<Workstation*>& objects, vector<CustomerOrder>& objToFill);
    /*with the following arguments :
	a reference to an unmodifiable std::string.This string contains the filename specified by the user to be used for linking the 
	assembly line objects(example : AssemblyLine.txt)
		a reference to a std::vector<Workstation*> that contains the addresses of all the Workstation objects created for the assembly line
		a reference to a std::vector<CustomerOrder> that contains all the CustomerOrder objects to be filled
		the constructor will :
	read the records from file and setup all the m_pNextStation references in the Workstation objects, 
	linking each Workstation object together to form the assembly line
		Move all the CustomerOrder objects onto the back of the ToBeFilled queue
		Copy all the Workstation objects into the AssemblyLine container*/
		
			bool run(ostream& os); // – this function performs one cycle of operations on the assembly line by doing the following :
/*Insert into os the iteration number(how many times this function has been called by the client; use only local variables to count) in 
the format Line Manager Iteration : COUNT<endl>
		If there are any CustomerOrder objects in the ToBeFilled queue, move the one at the front of the queue onto the starting point
		of the AssemblyLine(you have to identify which station is the starting point of your assembly line).Only one order can be moved on 
		the assembly line on each call to this function.
		Loop through all stations on the assembly lineand run one cycle of the station's process
		Loop through all stations on the assembly line and move the CustomerOrder objects down the line.
		Hint : completed orders should be moved into the Completed queue.
		return true if all customer orders have been filled, otherwise returns false.*/
	
			void displayCompletedOrders(ostream& os) const; // --displays all the orders that were completed

			void displayStations() const; // --display all stations on the assembly line in the order they were received from the client

			void displayStationsSorted() const; // --display all stations on the assembly line in the order they are linked.
	};





#endif