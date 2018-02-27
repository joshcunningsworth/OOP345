/*
 * Task.h
 *
 *  Created on: Nov 17, 2015
 *      Author: Josh
 */

#pragma once
#include <iostream>
#include <string>

class Task{
	std::string name;
    std::string slots;
    std::string nextTask[2];
    const Task* pNextTask[2];
    static char delimiter;
    static size_t field_width;

public:
    enum Quality{
        passed,
        redirect
    };

    Task(const std::string& record);

	const std::string& getName() const;
		//returns the name of the task


	const unsigned int getSlots() const;
		//returns the number of product slots in the task (converts from a string)


	bool validate(const Task&);
		//attempts to validate a next task in the current object by comparing the Task referenced
		//in its parameter to the next tasks stored upon instantiation.
		//If one of these tasks has the same name as that referenced,
		//this function sets the corresponding pointer to the address of the referenced task.


	const Task* getNextTask(Quality) const;
		//returns the address of the next task depending on the parameter received.
		//This function reports an exception as shown in the sample output below if the addressed
		//of that next task has not been determined (by validate())


	void display(std::ostream&) const;
		//inserts into the referenced ostream object a full description of the task as shown
		//in the sample output listed below if the task has been validated uses the pointer(s)
		//to the next task(s) if the task has not been validated uses the name(s) of the next task(s)
		//and appends a note that validation is still required


	static void setDelimiter(const char c);
		//reset the delimiter for all objects in this class to the character received


	static size_t getFieldWidth();
		//returns the field width for all objects in this class

};

bool operator==(const Task&, const Task&);
		//returns true if the tasks referenced in its parameters have the same name


