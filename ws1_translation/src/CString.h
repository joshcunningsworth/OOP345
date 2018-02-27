/*
CString.h
*/

#include "iostream"
#ifndef CSTRING_H_
#define CSTRING_H_

const int MAX = 3;
static int globalInsertions = 0;


namespace ws1{
    class CString; // just tell the compiler to expect a class def
}

class ws1::CString {
	char data[MAX+1];
public:
	CString(char* s);
	void display(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, ws1::CString& tempstring);

#endif /* CSTRING_H_ */
