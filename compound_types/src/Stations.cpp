/*
 * Stations.cpp
 *
 *  Created on: Sep 22, 2015
 *      Author: Josh
 */


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stations.h"


namespace w2{

Stations::Stations(){
	stationTable = 0;
	stationCount = 0;
}

Stations::Stations(char *filename){
	stationCount = 0;

	std::fstream fs(filename);
	if(!fs.is_open()){
		std::cerr << "Can't open the file (" << filename << ")\n";
		exit(1);
	}

	fs >> stationCount; // reading from file

	char c;
	fs.get(c);
	if(c!= ';'){
		std::cerr << "expected ; but found '" << c << "'\n";
		exit(2);
	}

	fs.get(c);
	if(c!= '\n'){
		std::cerr << "expected \\n but found '" << c << "'\n";
		exit(3);
	}


	stationTable = new Station*[stationCount];


	for(int s = 0; s < stationCount; s++){
		stationTable[s] = new Station(fs);
	}

	fs.close();
}

void Stations::update() const{
	int studpass = 0, adultpass = 0;


	std::cout << "Passes Sold :\n-------------\n";
	for(int x = 0; x < stationCount; x++){
		std::cout << stationTable[x] -> getName() << "\n";

		std::cout << "Student Passes Sold: ";
		std::cin >> studpass;
		std::cout << "\n";
		studpass = -studpass;

		stationTable[x] -> update(STUDENT_PASS, studpass);

		std::cout << "Adult Passes Sold: ";
		std::cin >> adultpass;
		std::cout << "\n";
		adultpass = -adultpass;

		stationTable[x] -> update(ADULT_PASS, adultpass);
	}
}

void Stations::restock() const{
	int studpass = 0, adultpass = 0;


	std::cout << "Passes Added :\n-------------\n";
	for(int x = 0; x < stationCount; x++){
		std::cout << stationTable[x] -> getName() << "\n";

		std::cout << "Student Passes Added: ";
		std::cin >> studpass;
		std::cout << "\n";

		stationTable[x] -> update(STUDENT_PASS, studpass);

		std::cout << "Adult Passes Added: ";
		std::cin >> adultpass;
		std::cout << "\n";

		stationTable[x] -> update(ADULT_PASS, adultpass);
	}
}

void Stations::report() const{
	std::cout << "Passes in Stock : Student Adult\n";
	std::cout << "-------------------------------\n";

	for(int s=0; s < stationCount;s++){
		std::cout << std::left << std::setw(18) << stationTable[s] -> getName();
		std::cout << std::setw(8) << stationTable[s] -> inStock(STUDENT_PASS);
		std::cout << std::setw(8) << stationTable[s] -> inStock(ADULT_PASS);
		std:: cout << "\n";
	}
}

}
