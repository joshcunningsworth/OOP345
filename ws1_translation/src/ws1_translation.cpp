/*============================================================================
	Name        : ws1_translation.cpp
	Author      : Josh Cunningham
	Description : OOP345 Workshop 1
============================================================================*/

// run configuration set with arg1 and arg2

#include <iostream>
#include <string>

namespace w1{
	const int SIZE = 4;
	class CString{

	};
}

int main(int argc, char *argv[]) {
	std::cout << "Argument Count (argc) = " << argc << std::endl;

	for(int i = 1; i < argc; i++){
		std::cout << "arg[" << argv[i] << "]" << std::endl;
	}

	std::cout << "Command Line : " << argv[0];


	/* const char learn = R"outcome(Upon successful completion of this workshop, I have demonstrated the ability
to link to a variable in another translation unit
to declare a local variable that lasts the lifetime of the program
to guard a class definition from repetition
to define a class within its own namespace
to pass arguments to program from the command line)outcome"; */

	return 0;
}
