/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

/*
* Display a student's data.
* temp: student whose data will be displayed
* index: location of the student within the hash table
* 
* returns: nothing
*/
void displayRecord(struct student* temp, int index)
{
	printf("%-5d  %-20s  %-9s  %-17s  %-7d  %-.1f\n", index,
						temp->name, temp->number, temp->email,
						temp->credits, temp->gpa);
}

/*
* Test if student's email address has valid format.
* temp: student data to test
* 
* returns: true if email address format is valid; otherwise, false
*/
bool testEmailFormat(struct student temp)
{
	if(temp.email[0] != 'u' || temp.email[9] != '@' || temp.email[13] != '.'
			|| temp.email[10] != 'u' || temp.email[11] != 'f' || temp.email[12] != 'b'
					|| temp.email[14] != 'e' || temp.email[15] != 'd' || temp.email[16] != 'u')
	{
		displayError(emailFormat, temp.email);
		return false;
	}
	else
	{
		return true;
	}
}

/*
* Test student's data for errors.
* temp: student data to test
* 
* returns: true if student data is valid; otherwise, false
*/
bool testStudentData(struct student temp)
{
	if(strlen(temp.name) > 20 || strlen(temp.name) < 5)
	{
		displayError(nameLength, temp.name);
		return false;
	}
	else if(strlen(temp.number) != 9)
	{
		displayError(numberLength, temp.number);
		return false;
	}
	else if(temp.number[0] != 'u')
	{
		displayError(numberFormat, temp.number);
		return false;
	}
	else if(strlen(temp.email) != 17)
	{
		displayError(emailLength, temp.email);
		return false;
	}
	else if(!testEmailFormat(temp))
	{
		return false;
	}
	else if(temp.credits < 0 || temp.credits > 150)
	{
		char intToString[10];
		sprintf(intToString, "%d", temp.credits);
		displayError(creditValue, intToString);
		return false;
	}
	else if(temp.gpa < 0 || temp.gpa > 4.0)
	{
		char doubToString[10];
		sprintf(doubToString, "%.1f", temp.gpa);
		displayError(gpaValue, doubToString);
		return false;
	}
	else
	{
		return true;
	}
}
