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
* Display the selected error message using the provided error information.
* errorType: the type of error that occurred
* errorInfo: additional information about the error
* 
* returns: nothing
*/
void displayError(int errorType, char* errorInfo)
{
	switch (errorType) {
		case generalError:
			printf("Missing Command-Line Arguments. [Input File] [Search File]\n");
			break;
		case fileError:
			printf("Error: File Not Found\n");
			break;
		case blankRecord:
			printf("Error: Blank Record Found \n");
			break;
		case corruptRecord:
			printf("Error: Corrupt Record (%s)\n", errorInfo);
			break;
		case shortRecord:
			printf("Error: Short Record (%s)\n", errorInfo);
			break;
		case duplicateName:
			printf("Error: Duplicate Student Name (%s)\n", errorInfo);
			break;
		case nameLength:
			printf("Error: Student Name Not Between 5 And 20 Characters (%s)\n", errorInfo);
			break;
		case numberLength:
			printf("Error: Student Number Is Not 9 Characters(%s)\n", errorInfo);
			break;
		case numberFormat:
			printf("Error: Student Number Is Invalid (%s)\n", errorInfo);
			break;
		case emailLength:
			printf("Error: Student Email Not 17 Characters (%s)\n", errorInfo);
			break;
		case emailFormat:
			printf("Error: Student Email Format Is Invalid (%s)\n", errorInfo);
			break;
		case creditValue:
			printf("Error: Student Credit Not Less Than 150 (%s)\n", errorInfo);
			break;
		case gpaValue:
			printf("Error: Student GPA Not Less Than 4.0 (%s)\n", errorInfo);
			break;
	}
	
}
