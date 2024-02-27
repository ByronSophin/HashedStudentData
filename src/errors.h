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

// Keywords used to display appropriate error message
enum errors {generalError, fileError, blankRecord, corruptRecord, shortRecord
, duplicateName, nameLength, numberLength, numberFormat, emailLength, emailFormat,
creditValue, gpaValue};

// Function Prototypes
void displayError(int errorType, char* errorInfo);
