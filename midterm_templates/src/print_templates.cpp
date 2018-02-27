//============================================================================
// Name        : print_templates.cpp
// Author      : Josh Cunningham
// Date		   : Monday, November 9th 2015.
// Copyright   : Anyone can copy don't worry, it's okay
// Description : Mid-Term Make-Up Test for C++ Wizards only
//============================================================================

#include <iostream>
using namespace std;

template <typename n>
void print(n&& rnum){
	cout << "R-Value: " << rnum << endl;
}

template <typename n>
void print(n& lnum){
	cout << "L-Value: " << lnum << endl;
}

int main(){

	char broiled = 'X';
	float icecream = 42;
	double trouble = 665.0;

	print(broiled);
	print(icecream);
	print(trouble);
	print(9);
	print(2+10.6);
	print(trouble+1);

	return 0;
}
