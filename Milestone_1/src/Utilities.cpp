/*
 * Utilities.cpp
 *
 *  Created on: Nov 17, 2015
 *      Author: Josh
 */

#include "Utilities.h"
#include <iostream>

char Utilities::delimiter = '\0';
//const int MAX_TOKENS_PER_LINE = 20;
//const char* const DELIMITER = "|";


//ctor
Utilities::Utilities(size_t minimum_field_width) : field_width(minimum_field_width){}

void Utilities::setFieldWidth(size_t fw){
	field_width = fw;		//resetting the field width to the value passed in
	//std::cout << "field width is set. no return because function is void" << std::endl;
}

size_t Utilities::getFieldWidth() const{
	return field_width;		//returns the field width
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& repeat){
	std::string token = "";

	//read token until delimiter
	while(str.size() != next_pos && str[next_pos] != delimiter){
		token += str[next_pos];
		next_pos++;
	}

	if(str.size() == next_pos){
		repeat = false;
	}

	else{
		repeat = true;
		next_pos++;
	}

	//trims white space, tab, and carriage return
	size_t p = token.find_first_not_of(" \t\r\n");
	token.erase(0, p);

	p = token.find_last_not_of(" \t\r\n");
	if(std::string::npos != p){
		token.erase(p+1);
	}

	if(field_width < token.size()){
		field_width = token.size();
	}

	return token;
}

void Utilities::setDelimiter(const char c){
	delimiter = c;			//resetting the delimiter to the value passed in
}

const char Utilities::getDelimiter(){
	return delimiter;		//returns the delimiter
}
