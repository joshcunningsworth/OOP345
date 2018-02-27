/*
 * Text.h
 *
 *  Created on: Sep 29, 2015
 *      Author: Josh
 */
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef TEXT_H_
#define TEXT_H_

namespace w3{

class Text{
	size_t lineCount;
	string* lineTable;

public:

	~Text(){ if(lineTable) delete [] lineTable; } 	//in line dtor
	Text() : lineCount(0), lineTable(nullptr){}		//default ctor
	Text(const char* filename) : lineCount(0), lineTable(nullptr){
		fstream fs(filename);
		if(fs.is_open()){
			string s;
			while(getline(fs,s)){
				lineCount++;
			}

			cout << "the file named (" << filename << ") has " << lineCount << " lines\n";

			fs.clear();
			fs.seekg(0,ios::beg);

			lineTable = new string[lineCount];
			for(size_t l = 0; l < lineCount; l++){
				getline(fs, lineTable[l]);
			}

#ifdef DEBUG
			for(size_t l = 0; l < lineCount; l++){
				cout << "line (" << l << ") is -->" << lineTable[l] << "<--\n";
			}
#endif
			fs.close();
		}else{
			cerr << "Can't open the file named (" << filename << ")\n";
		}
	}


	size_t size(){ return lineCount; } 	//in line function


	Text& operator= (const Text& rhs){
		if(this != &rhs){
			if(lineTable) delete []lineTable;	//in line if statement
			//deep copy rhs to this
			lineCount = rhs.lineCount;
			lineTable = new string[lineCount];
			for(size_t l = 0; l < lineCount; l++){
				lineTable[l] = rhs.lineTable[l];
			}
		}
		return *this; 	//rhs was copied to this and now it's returned
	}

	Text(const Text& rhs){
		lineTable = nullptr;
		*this = rhs;
	}

	Text& operator= (Text&& rhs){
		if(this != &rhs){
			if(lineTable) delete [] lineTable;
		}

		lineCount = rhs.lineCount;
		lineTable = rhs.lineTable;

		rhs.lineCount = 0;
		rhs.lineTable = nullptr;

		return *this;

		}

	Text(Text&& rhs){
		lineTable = nullptr;
		*this = rhs;
	}
};

}

#endif /* TEXT_H_ */
