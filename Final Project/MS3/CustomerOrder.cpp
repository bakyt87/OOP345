// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 05.04.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
#include "CustomerOrder.h"
using namespace std;


	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {
		m_name = ""; // – the name of the customer(e.g., John, Sara, etc)
		m_product = ""; // – the name of the product being assembled(e.g., Desktop, Laptop, etc)
		m_cntItem = 0u; // – a count of the number of items for the customer's order
		m_lstItem = nullptr; // – a dynamically allocated array of pointers.Each element of the array is a
	}
	CustomerOrder::CustomerOrder(std::string str) {
		m_name = ""; // – the name of the customer(e.g., John, Sara, etc)
		m_product = ""; // – the name of the product being assembled(e.g., Desktop, Laptop, etc)
		m_cntItem = 0; // – a count of the number of items for the customer's order
		m_lstItem = nullptr; // – a dynamically allocated array of pointers.Each element of the array is a
		bool more = true;
		size_t pos = 0;
	    int count = 0u;
		size_t itemPos = 0u;
		
		Utilities obj;
		obj.setFieldWidth(m_widthField);
		while (more) {
			if (count == 0) m_name = obj.extractToken(str, pos, more);
			else if (count == 1) m_product = obj.extractToken(str, pos, more);
			else if (count == 2) {
				itemPos = pos;
				while (more) {
					obj.extractToken(str, pos, more);
					m_cntItem++;
				}
				more = true;
				m_lstItem = new Item * [m_cntItem];
				m_cntItem = 0;
				pos = itemPos;
			}
			else {
				m_lstItem[m_cntItem] = new Item(obj.extractToken(str, pos, more));
				m_cntItem++;
			}
			count++;
		}

	}
	CustomerOrder::CustomerOrder(const CustomerOrder& src) {
		std::string err = "Copy constructor cannot be called";
			throw err;
	}
	
	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
		m_name = ""; // – the name of the customer(e.g., John, Sara, etc)
		m_product = ""; // – the name of the product being assembled(e.g., Desktop, Laptop, etc)
		m_cntItem = 0; // – a count of the number of items for the customer's order
		m_lstItem = nullptr; // – a dynamically allocated array of pointers.Each element of the array is a

		*this = std::move(src);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
		

		if (this != &src) {
			if (m_lstItem != nullptr) {
				for (size_t i = 0u; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			m_widthField = src.m_widthField;
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
			src.m_widthField = 0;
		}
			return *this;
		
	}
	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0u; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}
	bool CustomerOrder::isOrderFilled() const {
		bool res =true;
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == false) {
			res = false;
			}
		}
		return res;
	}//returns true if all the items in the order have been filled; false otherwise
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool res = true;
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == itemName) {
				res = m_lstItem[i]->m_isFilled;
			}
		}
		return res;
	
	}//returns the ItemInfo::m_fillState of the item specified as a parameter.If the item doesn't exist in the order, return true.
	void CustomerOrder::fillItem(Station& station, std::ostream& os ) {
		for (auto i = 0u; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName) {
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = 1;
					station.updateQuantity();

					os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
				}
			}
		}
        }
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name <<" - "<< m_product << endl;
		for (size_t i = 0u; i < m_cntItem; i++) {
			os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] "<< 
				std::setw(16)<< std::setfill(' ')<<std::left << m_lstItem[i]->m_itemName << " - "
				<< (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << std::endl;
		}

	}
