/*
 * Task.cpp
 *
 *  Created on: Nov 17, 2015
 *      Author: Josh Cunningham
 */

#include "Task.h"
#include "Utilities.h"
#include <iomanip>
#include <fstream>
//#include <regex>

#define WIDTH size_t (20)

//Initialising static variables
char Task::delimiter = '\0';
size_t Task::field_width = 0;

//const int MAX_CHARS_PER_LINE = 512;
//const int MAX_TOKENS_PER_LINE = 20;
//const char* const DELIMITER = "|";

//ctor
Task::Task(const std::string& record) : name(""), slots("1"){

	/*
	 *
	std::cout << "is this even working?" << std::endl;

	ifstream fin;
	fin.open("TaskList_Clean.txt"); 		//open a file
	  if (!fin.good())
	    return 1; 							//exit if file not found

	  	  	  	  	  	  	  	  	  	  	//read each line of the file
	  while (!fin.eof()){
	  // read an entire line into memory
		char buf[MAX_CHARS_PER_LINE];
	    fin.getline(buf, MAX_CHARS_PER_LINE);

	    // parse the line into blank-delimited tokens
	    int n = 0; // a for-loop index

	    // array to store memory addresses of the tokens in buf
	    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialise to 0

	    // parse the line
	    token[0] = strtok(buf, DELIMITER); // first token
	    if (token[0]) // zero if line is blank{
	      for (n = 1; n < MAX_TOKENS_PER_LINE; n++){
	        token[n] = strtok(0, DELIMITER); // subsequent tokens
	        if (!token[n]) break; // no repeat tokens then break
	      }
	    }

	    // print the tokens
	    for (int i = 0; i < n; i++) // n = number of tokens
	      cout << "Token[" << i << "] = " << token[i] << endl;
	    cout << endl;
	  }
	 *
	 */
	nextTask[passed] = "";
	nextTask[redirect] = "";
	pNextTask[passed] = nullptr;
	pNextTask[redirect] = nullptr;


	Utilities util(field_width);


	size_t position = 0;
	bool repeat = true;

	name = util.nextToken(record, position, repeat);
	if (!name.empty()){
		if (repeat == true){		//if repeat is true then continue to look for tokens
			slots = util.nextToken(record, position, repeat);
		}

		if (repeat == true){
			nextTask[passed] = util.nextToken(record, position, repeat);
		}

		if (repeat == true){
			nextTask[redirect] = util.nextToken(record, position, repeat);
		}

		if (util.getFieldWidth() < WIDTH){
			field_width = util.getFieldWidth();
		}
	}
}

const std::string& Task::getName() const{
	return name;				//returns the name of the task
}

const unsigned int Task::getSlots() const{
	return std::stoi(slots);	//returns the amount of product slots converted from a string to a number
}

bool Task::validate(const Task& task){
	if(!pNextTask[passed] && !nextTask[passed].compare(task.name)){
		pNextTask[passed] = &task;
	}

	if(!pNextTask[redirect] && !nextTask[redirect].compare(task.name)){
		pNextTask[redirect] = &task;
	}

	return (nextTask[passed].empty() || pNextTask[passed]) && (nextTask[redirect].empty() || pNextTask[redirect]);
}

const Task* Task::getNextTask(Quality qlty) const{
	if(!pNextTask[qlty]){
		throw std::string("*** Validate  [") + nextTask[qlty] + std::string("] @ [") + name + std::string("] ***");
	}

	return pNextTask[qlty];
}

void Task::display(std::ostream& os) const{
	size_t fw = field_width + 2;

	os << "Task Name    : " << std::left;
	os << std::setw(fw) << (std::string("[") + name + std::string("]"));
	os << " [" << slots << "]";
	os << std::endl;

	if (!nextTask[passed].empty())
	{
		os << " Continue to : ";
		os << std::setw(fw) << (std::string("[") + nextTask[passed] + std::string("]"));
		if (!pNextTask[passed]) os << " *** to be validated ***";
		os << std::endl;
	}

	if (!nextTask[redirect].empty())
	{
		os << " Redirect to : ";
		os << std::setw(fw) << (std::string("[") + nextTask[redirect] + std::string("]"));
		if (!pNextTask[redirect]) os << " *** to be validated ***";
		os << std::endl;
	}
}

void Task::setDelimiter(const char c){
	delimiter = c;				//resetting the delimiter to the value passed in
}

size_t Task::getFieldWidth(){
	return field_width;			//returns the field width
}

bool operator==(const Task& task1, const Task& task2){
								//task1 = left hand value
								//task2 = right hand value
	return !task1.getName().compare(task2.getName());
}

