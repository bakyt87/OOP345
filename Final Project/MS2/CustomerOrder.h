#pragma once
#ifndef SDT_CUSTOMERORDER_H
#define STD_CUSTOMERORDER_H
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>
#include "Station.h"
#include "Utilities.h"


namespace std {
	struct Item
	{
		std::string m_itemName;
		unsigned int m_serialNumber = 0;
		bool m_isFilled = false;

		Item(const std::string& src) : m_itemName(src) {};
	};
	class CustomerOrder {
		std::string m_name; // – the name of the customer(e.g., John, Sara, etc)
		std::string m_product; // – the name of the product being assembled(e.g., Desktop, Laptop, etc)
		unsigned int m_cntItem; // – a count of the number of items for the customer's order
		Item** m_lstItem; // – a dynamically allocated array of pointers.Each element of the array is a
						  // dynamically allocated object of type Item(see below).This is the resource that your class must manage.
		static size_t m_widthField; // – the maximum width of a field, used for display purposes
	public:
		CustomerOrder();
		CustomerOrder(std::string);
		~CustomerOrder();
		CustomerOrder(const CustomerOrder& src);
		CustomerOrder& operator=(const CustomerOrder& src) = delete;
		CustomerOrder(CustomerOrder&& src)noexcept;
		CustomerOrder& operator=(CustomerOrder&& src)noexcept;
		bool isOrderFilled() const; //returns true if all the items in the order have been filled; false otherwise
		bool isItemFilled(const std::string& itemName) const; //returns the ItemInfo::m_fillState of the item specified as a parameter.If the item doesn't exist in the order, return true.
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};


}








#endif