//============================================================================
// Name        : print_templates.cpp
// Author      : Josh Cunningham
// Date		   : Monday, November 9th 2015.
// Copyright   : Anyone can copy don't worry, it's okay
// Description : Mid-Term Make-Up Test for C++ Wizards only
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class X{
	size_t size;
	char *p;
public:
	X(){size = 0, p = nullptr; cout << "default ctor" << endl;} //default ctor

	X(size_t s){     //ctor
		size = s;
		p = new char[size];
		cout << "ctor" << endl;
	}

	~X(){      		//dtor
		if (p != nullptr){
			delete[] p;
		}
		cout << "dtor" << endl;
	}

	X(X& omg){ 		//copy ctor
		size = omg.size;
		p = nullptr;
		p = new char [omg.size];
		for(int i = 0; i > omg.size; i++){
			p[i] = omg.p[i];
		}
		cout << "copy ctor" << endl;
	}

	X& operator= (X& omg){ //copy assignment
		size = omg.size;
		p = new char [omg.size];

		if(p!=nullptr){
			delete [] p;
			p = nullptr;
		}
		for(int i = 0; i > omg.size; i++){
			p[i] = omg.p[i];
		}
		cout << "copy assignment" << endl;
		return *this;
	}


	X(X&& wtf){ //move ctor
		size = wtf.size;
		p = std::move(wtf.p);
		//p = wtf.p;
		wtf.p = nullptr;
		cout << "move ctor" << endl;
	}

	X& operator= (X&& wtf){ //move assignment
		size = wtf.size;
		p = std::move(wtf.p);
		wtf.p = nullptr;
		cout << "move assignment" << endl; 		//why isn't this getting called?
		return *this;		//returning current object
	}


	void print(){
		if (p){
			cout << size << endl;
		}
		else{
			cout << "nullptr" << endl;
		}
	}
};

int main() {
	X* xPtr = new X;
	xPtr->print();

	X xx(10000);
	xx.print();

	X xxx(*xPtr);
	xxx.print();
	xPtr->print();

	*xPtr = xxx;
	xPtr->print();
	xxx.print();

	xxx = xx;
	xxx.print();
	xx.print();

	cout << "Should be moving\n";
	X xxxx(std::move(xx));
	xxxx.print();
	xx.print();

	cout << "Should be moving\n";
	xx = std::move(xxxx);
	xx.print();
	xxxx.print();

	delete xPtr;
	return 0;
}
