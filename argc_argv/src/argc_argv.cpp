//============================================================================
// Name        : argc_argv.cpp
// Author      : Josh Cunningham
// Description : Practice with command line arguments and practice for workshop 1
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 3;

class Cstring{
	char str[MAX+1]; // +1 allocates space for '\0'
public:
	Cstring(char* param){
		if(param == nullptr){
			str[0] = '\0';
			return;
		}
		cout << "Cstring (" << param << ")";
		strncpy(str, param, MAX);
		str[MAX] = '\0';
		cout << "\nCstring stored -->" << param << "<--";
	}
	void display(ostream& os){
		os << str;
	}
};

void process(char* parm){
	cout << "process: parm -->" << parm << "<--\n";
	Cstring cs(parm);
	cs.display(cout);
	cout << "\n";
}

ostream& operator << (ostream& os, Cstring& cs){
	static int call = 1;
	os << call << ": ";
	cs.display(os);
	return os;
}

int main(int argc, char * argv[]) {
	//cout << "argc = " << argc << "\n";
	//for(int arg = 0; arg < argc; arg++)
	//	cout << "argv[" << arg << "]  -->" << argv[arg] << "<--\n";

	cout << "command line: ";
	for(int arg = 0; arg < argc; arg++){
		cout << "argv[" << arg << "]  -->" << argv[arg] << "<--\n";
	}

	if(argc == 1){
		cout << "Insufficient number of arguments (min 1)\n";
		return 1;
	}

	cout << "Maximum number of characters stored : " << MAX << "\n";

	for(int arg = 0; arg < argc; arg++){
		process(argv[arg]);
	}

	return 0;
}
