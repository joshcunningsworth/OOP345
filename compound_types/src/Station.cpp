/*
 * Station.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: Josh
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Station.h"


namespace w2{

Station::Station(){ 	// default constructor

}

Station::Station(std::fstream& fs){
	getline(fs, stationName, ';');

	fs >> passCounts[STUDENT_PASS];
	fs >> passCounts[ADULT_PASS];

	char c; //skipping '\n'
	fs.get(c);
	if(c!= '\n'){
		std::cerr << "expected \\n but found '" << c << "'\n";
		exit(4);
	}
}

void Station::set(const std::string& name, unsigned student, unsigned adult){
	stationName = name;
	passCounts[STUDENT_PASS] = student;
	passCounts[ADULT_PASS] = adult;
}

void Station::update(PassType pt, int number){
	passCounts[pt] += number;
}

unsigned Station::inStock(PassType pt) const{
	return passCounts[pt];
}

const std::string& Station::getName() const{
	return stationName;
}

}
