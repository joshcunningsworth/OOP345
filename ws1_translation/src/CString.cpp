/*
CString.cpp
*/

#include "CString.h"

ws1::CString::CString(char* s){
	globalInsertions++;
	if(s != nullptr){
		for(int x = 0; x < MAX; x++){
			data[x] = s[x];
			if(s[x] == '\0'){
				break;
			}
			else{
				data[0] = '\0';
			}
		}
	}
}
	void ws1::CString::display(std::ostream& os){
		os << data;
	}

std::ostream& operator<<(std::ostream& os, ws1::CString& tempstring){
	tempstring.display(os);
	return os;
}

