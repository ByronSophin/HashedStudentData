/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*  DO NOT MODIFY THIS FILE WITHOUT PERMISSION
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/
#pragma once

// Keywords used to perform appropriate search
enum searchTypes {creditEqual, creditLess, creditGreater, emailKey,
	emailContains, nameFull, nameFirst, nameLast, gpaEqual, gpaLess,
	gpaGreater, numberKey, numberContains};
				   
// Function Prototypes
void performSearch(struct student* hashTable[], char* type, char* string);
