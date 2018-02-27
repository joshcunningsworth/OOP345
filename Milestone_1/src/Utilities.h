/*
 * Utilities.h
 *
 *  Created on: Nov 17, 2015
 *      Author: Josh
 */

#pragma once
#include <string>

const unsigned int CODE_WIDTH = 5; // item code field width (later)

class Utilities{
    size_t field_width;
    static char delimiter;

public:

    Utilities(size_t minimum_field_width = 1u);
    	//Upon instantiation, a Utilities object receives the minimum value of the field
	 	//width to be used in displaying any token in a list of tokens.  The object’s
	 	//constructor initializes the field_width instance variable to this minimum value.


    void setFieldWidth(size_t fw);
    	//resets the field width to fw


    size_t getFieldWidth() const;
    	//returns the field width


    const std::string nextToken(const std::string& str, size_t& next_pos, bool& more);
    	//receives a reference to string str, a reference to the position (next_pos) in
    	//this string at which to start extracting the next token, and a reference to a
    	//boolean flag (more).  This function returns the next token found and sets more
    	//to true if the function has found more tokens after the extracted token; false otherwise.


    static void setDelimiter(const char c);
    	//resets the delimiter for this class to the character received


    static const char getDelimiter();
    	//returns the delimiter for this class

};
