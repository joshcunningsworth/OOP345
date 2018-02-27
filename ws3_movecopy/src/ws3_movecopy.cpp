//============================================================================
// Name        : ws3_movecopy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class text{
	uint64_t count = 0;
	string* linetable;

public:
	text() : count(0), linetable(nullptr){}
	text(char* filename) : count(0), linetable(nullptr){}
	text(const text& t){
		count = t.count;
		linetable = new string[count];
		for(int linenum = 0; linenum < count; linenum++){
			linetable[linenum] = t.linetable[linenum];
		}
	}
};

void process(char* filename){
	fstream fs(filename);
	if(fs){
		uint64_t count = 0;
		string line;
		while(getline(fs, line))
			count++;
		fs.clear();
		fs.seekg(streampos(0));
		cout << "File" << filename << "has" << count << "lines" << endl;

		string* linetable = new string[count];
		fs.seekp(0, ios::beg);
		for(int line = 0; line < count; line++){
			getline(fs, linetable[line]);
		}

		fs.close();
		for(int line = 0; line < 5; line++){
			cout << line << linetable[line];
		}
	}
	else{
		cerr << "The file" << filename << "cannot open" << endl;
	}
}

int main(int argc, char* argv[]) {
	for(int arg = 0; arg < argc; arg++){
		cout << " " << argv[arg];
	}

	cout << endl;

	return 0;
}
