/*
 * Station.h
 *
 *  Created on: Sep 22, 2015
 *      Author: Josh
 */

#pragma once

namespace w2{

enum PassType{
	STUDENT_PASS, 	//same as #define STUDENT_PASS 0
	ADULT_PASS,		//same as #define ADULT_PASS 1
	PASS_COUNT		//same as #define PASS_COUNT 2
};


class Station{
	std::string stationName;
	int passCounts[PASS_COUNT];

public:
	Station();
	Station(std::fstream&);
	void set(const std::string&, unsigned, unsigned);
	void update(PassType, int);
	unsigned inStock(PassType) const;
	const std::string& getName() const;
};

}
