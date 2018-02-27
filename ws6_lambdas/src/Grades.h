/*
 * Grades.h
 *
 *  Created on: Dec 7, 2015
 *      Author: Josh Cunningham
 */


#ifndef _GRADES_H_
#define _GRADES_H_

#include <iomanip>
#include <fstream>


class Grades{
	size_t size;
	int* numbers;
	double* grades;

public:
	Grades(const char* filename) : size(0), numbers(nullptr), grades(nullptr){
		std::fstream fs(filename);
		if (!fs){
			throw std::string("*** ERROR *** -- Unable to open file: ") + std::string(filename) + std::string(" -- ");
		}

		std::string line;
		size_t count = 0;

		while(getline(fs, line)){
			count++;
		}

		fs.clear();
		fs.seekg(0, std::ios::beg);

		numbers = new (std::nothrow) int[count];
		grades = new (std::nothrow) double[count];
		size = count;

		for(size_t i = 0; i < count; i++){
			fs >> numbers[i];
			fs >> grades[i];
		}
		fs.close();
	}

		virtual ~Grades(){
			delete[] numbers;
			delete[] grades;
		}

		void displayGrades(std::ostream& os, const char* (*express)(double)) const{
			for(size_t i = 0; i < size; i++){
				os << numbers[i] << ' ' << std::fixed << std::setprecision(2) << grades[i] << ' ' << express(grades[i]) << std::endl;
			}
		}
};

#endif 	// _GRADES_H_
