/*
 * Notifications.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: Josh
 */


#include <iostream>
#include <fstream>
#include "Notifications.h"

#define MAX_MESSAGES 10

namespace w5{

	Notifications::Notifications() : messages(new Message[MAX_MESSAGES]), size(0){}

	Notifications::Notifications(const Notifications& other){
		messages = nullptr;
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& rhs){
		if (this != &rhs){
			delete [] messages;

			size = rhs.size;
			if (rhs.messages){
				messages = new Message[MAX_MESSAGES];
				for(int i = 0; i < MAX_MESSAGES; i++){
					messages[i] = rhs.messages[i];
				}
			}
			else{
				messages = nullptr;
			}
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& other){
		messages = nullptr;
		*this = std::move(other);
	}

	Notifications&& Notifications::operator=(Notifications&& rhs){
		if (this != &rhs){
			delete [] messages;

			messages = rhs.messages;
			size = rhs.size;

			rhs.messages = nullptr;
			rhs.size = 0;
		}
		return std::move(*this);
	}

	Notifications::~Notifications(){
		delete [] messages;
	}

	void Notifications::operator+=(const Message& msg){
		if (size < MAX_MESSAGES){
			messages[size++] = msg;
		}
	}

	void Notifications::display(std::ostream& os) const{
		for(int i = 0; i < size; i++){
			messages[i].display(os);
			os << std::endl;
		}
	}
}
