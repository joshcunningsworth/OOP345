//============================================================================
// Name        : file-test.cpp
// Author      : Josh Cunningham
// Version     : 1.0
// Date		   : December 14, 2015
// Description : Simple program for creating/saving a file
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

int main(){

	std::ofstream o("save.txt");
	o << "Hello, World\n" << std::endl;

	return 0;
}
