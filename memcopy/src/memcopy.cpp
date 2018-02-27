//============================================================================
// Name        : memcopy.cpp
// Author      : Josh Cunningham
// Date		   : Thursday, December 10th 2015
// Description : memcpy example
//============================================================================

/* memcpy example */
#include <stdio.h>
#include <string.h>

class memcopy{
public:
	char name[40];
	int age;
}

person, person_copy;

int main(){
	char myname[] = "Josh Cunningham";

	//using memcpy to copy string:
	memcpy (person.name, myname, strlen(myname)+1);
	person.age = 46;

	//using memcpy to copy structure:
	memcpy (&person_copy, &person, sizeof(person));

	printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	return 0;
}
