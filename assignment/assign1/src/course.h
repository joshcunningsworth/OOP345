/*
 * course.h
 *
 *  Created on: Apr 10, 2015
 *      Author: Josh
 */

#pragma once

#include <string>
#include <vector>
#include "object.h"

class cartoon: public object{
	std::string Name;
	std::string CPA;
	std::string BSD;

  public:
    // when derived objects may contain pointers, virtual destructors are necessary
    virtual ~course();

    // (optional) use set to assign values to their respective data members of the derived object
    virtual void set(std::vector<std::pair<std::string,std::string>>);

    // (required) returns member data as Delimited Separated Values (default separator is comma)
    virtual const std::string to_DSV(const char c=',');

    // (required) returns member data as simple indented json; item is indented by number of leading spaces 
    virtual const std::string to_json(int leading_spaces=0);
};

cartoon::~course(){
  
}


/*
	just for reference
        "Name": "Game Engine Techniques",
        "CPA": "GAM532",
        "BSD": "DPS932"
*/

// (optional) use set to assign values to their respective data members of the derived object
void cartoon::set(std::vector<std::pair<std::string,std::string>> v) {
	for(auto e : v){
		cout << e.first << “,” << e.second << "\n";
		if(e.first == “Name”) Name = e.second;
		else if(e.first == “CPA”) CPA = e.second;
		else if(e.first == “BSD”) BSD = e.second;
	}
	cout << Name << "," << CPA << "," << BSD << "\n";
}

// (required) returns member data as Delimited Separated Values (default separator is comma)
const std::string cartoon::to_DSV(const char c){
	return Name + c + CPA + c + BSD + "\n";
}

// (required) returns member data as simple indented json; item is indented by number of leading spaces 
const std::string cartoon::to_json(int leading_spaces){
	
	std::string spaces(leading_spaces, ' ');
	return 
		spaces + "{\n" +
		spaces + spaces + “\”Name\”: " +  "\"" + Name + "\"" ",\n" +
		spaces + spaces + “\”CPA\”: " +  "\"" + CPA + "\"" ",\n" +
		spaces + spaces + “\”BSD\”: " +  "\"" + BSD + "\"" + "\n" +
		"}"
		;
}
