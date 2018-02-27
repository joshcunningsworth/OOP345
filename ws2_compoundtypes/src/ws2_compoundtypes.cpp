//============================================================================
// Name        : ws2_compoundtypes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

enum passtype_e{
	STUDENT_PASS, ADULT_PASS, PASS_TYPE_COUNT
};

class Station{
	string name;
	int passes[PASS_TYPE_COUNT];
public:
	Station() { }
	void Read (fstream);
	Station(fstream& fs){
		getline(fs, name, ';');
		cout << "name=" << name << "\n";
		fs >> passes[STUDENT_PASS] >> passes[ADULT_PASS];

		cout << "student, adult=" << passes[STUDENT_PASS] << "," << passes[ADULT_PASS] << "\n";
	}
};

class Stations {
	int stationcount;
	fstream fs;
public:
	Stations(char* filename){
		fs.open(filename);
		if(fs){
			string s;
			getline(fs, s, ';');
			stringstream ss(s);
			ss >> stationcount;
			cout << "station count = " << stationcount << "\n";
		}
		else{
			cerr << "Cannot open the file";
		}
	}
};

void Process(char *filename){
	Stations stations(filename);

}

int main(int argc, char *argv[]) {
	cout << "Command Line : ";
	for(int arg = 0; arg < argc; arg++){
		cout << " ";
	}
	return 0;
}
