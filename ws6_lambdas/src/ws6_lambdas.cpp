//============================================================================
// Name        : ws6_lambdas.cpp
// Author      : Josh Cunningham
// Version     : v1.0 - Dec 7, 2015
// Description : Use lambda expression to define an operation on a set of values
// reads the values from a file and displays them to the user.
//============================================================================


#include <iostream>
#include "Grades.h"


int main(int argc, char* argv[]){

	if (argc != 2){
		std::cerr << argv[0] << ": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	try{
		Grades grades(argv[1]);

		auto letter = [] (double grade){
			if (grade >= 90 && grade <= 100) return "A+";
			else if (grade >= 80 && grade <=  89) return "A";
			else if (grade >= 75 && grade <=  79) return "B+";
			else if (grade >= 70 && grade <=  74) return "B";
			else if (grade >= 65 && grade <=  69) return "C+";
			else if (grade >= 60 && grade <=  64) return "C";
			else if (grade >= 55 && grade <=  59) return "D+";
			else if (grade >= 50 && grade <=  54) return "D";
			else return "F";
		};

		grades.displayGrades(std::cout, letter);
	}
    catch (const std::string& msg){
        std::cerr << msg << std::endl;
    }
    catch (const char* msg){
        std::cerr << msg << std::endl;
    }

	std::cout << "Press the enter key to continue ... ";
	std::cin.get();

	return 0;
}
