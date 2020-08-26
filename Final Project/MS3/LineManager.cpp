// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iomanip>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>
#include "LineManager.h"
using namespace std;

	size_t LineManager::count = 1u;
	LineManager::LineManager() :m_cntCustomerOrder{ 0 } {}
	//custom constructor
	LineManager::LineManager(std::string str, std::vector<Workstation*>& objects, std::vector<CustomerOrder>& objToFill) {
		string item;
		string  next;
		string record;
		fstream file(str);
		Utilities util;
		size_t pos = 0;
		
		while (file)
		{
			bool more = true;
			while (getline(file, record))
			{
				item = util.extractToken(record, pos, more);
				for (auto i : objects)
				{
					if (item == i->getItemName())
					{
						if (more)
						{
							next = util.extractToken(record, pos, more);

							for (auto j : objects)

								if (next == j->getItemName())
								{
									i->setNextStation(*j);
								}
						}
                        Sorted_AssemblyLine.push_back(i);
					}
				}
			}
		}
			AssemblyLine = objects;
			m_cntCustomerOrder = objToFill.size();
			ToBeFilled = deque<CustomerOrder>(m_cntCustomerOrder);
			for (auto i = 0u; i < m_cntCustomerOrder; i++)
			{
				ToBeFilled[i] = move(objToFill[i]);
			}
		
	}
	/*with the following arguments :
		a reference to an unmodifiable std::string.This string contains the filename specified by the user to be used for linking the assembly 
		line objects(example : AssemblyLine.txt)
			a reference to a std::vector<Workstation*> that contains the addresses of all the Workstation objects created for the assembly line
			a reference to a std::vector<CustomerOrder> that contains all the CustomerOrder objects to be filled
			the constructor will :
		read the records from file and setup all the m_pNextStation references in the Workstation objects,
		linking each Workstation object together to form the assembly line
			Move all the CustomerOrder objects onto the back of the ToBeFilled queue
			Copy all the Workstation objects into the AssemblyLine container*/

	bool LineManager::run(std::ostream& os) {
		

		CustomerOrder order;
        os << "Line Manager Iteration: " << count << endl;
		if (ToBeFilled.size() > 0)
		{
			*Sorted_AssemblyLine.at(0) += move(ToBeFilled.front());
			ToBeFilled.pop_front();
		}
        for (auto i : AssemblyLine) {
			i->runProcess(os);
		}
		for (auto i : AssemblyLine) {
			i->moveOrder();
            if (i->getIfCompleted(order)) {
				Completed.push_back(move(order));
			}
		}
		count++;

		return Completed.size() == m_cntCustomerOrder;

	}// – this function performs one cycle of operations on the assembly line by doing the following :
/*Insert into os the iteration number(how many times this function has been called by the client; use 
only local variables to count) in the format Line Manager Iteration : COUNT<endl>
		If there are any CustomerOrder objects in the ToBeFilled queue, move the one at the front 
		of the queue onto the starting point of the AssemblyLine(you have to identify which station is the 
		starting point of your assembly line).Only one order can be moved on the assembly line on each call to this function.
		Loop through all stations on the assembly lineand run one cycle of the station's process
		Loop through all stations on the assembly line and move the CustomerOrder objects down the line.
		Hint : completed orders should be moved into the Completed queue.
		return true if all customer orders have been filled, otherwise returns false.*/

	void LineManager::displayCompletedOrders(ostream& os) const {
		for (auto i =Completed.begin(); i != Completed.end(); i++ ) {
			(*i).display(cout);
		}
		

	}// --displays all the orders that were completed

	void LineManager::displayStations() const {
		for (auto i :AssemblyLine) {
			i->display(cout);
		}

	}// --display all stations on the assembly line in the order they were received from the client

	void LineManager::displayStationsSorted() const {
		for (auto i : Sorted_AssemblyLine) {
		    i->display(cout);
		}


	}// --display all stations on the assembly line in the order they are linked.



