
// Name: Bakyt Kurmanov
// Seneca Student ID: 150582179
// Seneca email: bkurmanov@myseneca.ca
// Date of completion: 22.02.2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>

namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name="";
		T* array;
		size_t m_size;
		void (*observer)(const Collection<T>&, const T&)=nullptr;
	public:
		Collection(std::string name) {
			m_name = name;
			array = nullptr;
			m_size = 0;
		}
		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		~Collection() {
			delete[] array;
			array = nullptr;
		}
		const std::string& name() const {
			return m_name;
		}
		size_t size() const {
			return m_size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T& )) {
		
			this->observer = observer;
		}//stores the parameter into an attribute, to be used when an item is added to the collection.
		//The parameter is a pointer to a function that returns void and accepts two parameters :
		//a collectionand an item that has just been added to the collection.
		Collection<T>& operator+=(const T& item) {
			bool result = false;
			if(array !=nullptr){
				for (size_t i = 0; i < m_size && result ==false; i++) {
					if (array[i].title() == item.title()) {
						result = true;
					}
				}
			}
			else {
				array = new T[1];
				array[0] = item;
			}
			if (result == false && array !=nullptr) {
				T* temp=new T[m_size+1];
				for (size_t i = 0; i < m_size; i++) {

					temp[i] = array[i];
				}
			    temp[m_size] = item;
				m_size ++;
				array = std::move(temp);
				if (this->observer != nullptr) {
					observer(*this, item);
				}
				
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			
			std::string err = "Bad index [" + std::to_string(idx) + ". Collection has [" + std::to_string(m_size) + " ] items.";
			std::out_of_range error(err);
			if (idx > m_size) {
					throw error;
			}
			else {
				return array[idx];
			}
		}
		T* operator[](std::string title) const {
			bool res = false;
			T* ptr = nullptr;
			for (size_t i = 0; i < m_size && res==false; i++) {
				if (array[i].title() == title) {
					res = true;
					ptr = &(array[i]);
				}
			}
			return ptr;
		}
		//returns the address of the item with title title
		//(type T has a member function called title() that returns the title of the item).
			//If no such item exists, this function returns nullptr.
		
		
    };
	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& rhs) {
		for (size_t i = 0; i < rhs.size(); i++) {
			os << rhs[i];
		}
		return os;
	}

		/*overload the insertion operator to insert the content of a Collection object into an ostream
		object.Iterate over all elements in the collectionand insert each one into the ostream object(do not add newlines).*/
}


#endif