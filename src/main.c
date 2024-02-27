/*********************************************
*        DO NOT REMOVE THIS MESSAGE
*
* This file is provided by Professor Littleton
* to assist students with completing Project 1.
*
*        DO NOT REMOVE THIS MESSAGE
**********************************************/

#include "headers.h"

// Constants
#define INPUT_BUF_SIZE 60 // Size of the buffer used to read records from input file
#define	SEARCH_BUF_SIZE 25 // Size of the buffer used to read records from search file

// Function Prototypes
struct student createStudent(char record[]);
void processInputFile(struct student* hashTable[], char* filename);
void processSearchFile(struct student* hashTable[], char* filename);
bool testRecord(char record[]);


int main(int argc, char *argv[])
{
	if(argv[1] == NULL)
	{
		displayError(generalError, NULL);
	}
	else
	{
		struct student* hashTable[TABLE_SIZE];
		initializeTable(hashTable);
		processInputFile(hashTable, argv[1]);
		displayHashTable(hashTable);
		if(argv[2] != NULL)
		{
			processSearchFile(hashTable, argv[2]);
		}
	}
	return 0;
}

/* 
* Create a student using the provided data.
* record: String of student data
* 
* returns: The student containing the provided data
*/
struct student createStudent(char record[])
{
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// strcpy() - copies string data from one variable to another
	// strtol() - converts a string to its integer value
	// atof() 	- converts a string to its double value
	struct student newRecord;
	char* pointer;
	char* pnt;
	pointer = strtok(record, ",");
	strcpy(newRecord.name, pointer);
	pointer = strtok(NULL, ",");
	strcpy(newRecord.number, pointer);
	pointer = strtok(NULL, ",");
	strcpy(newRecord.email, pointer);
	pointer = strtok(NULL, ",");
	newRecord.credits = strtol(pointer, &pnt, 10);
	pointer = strtok(NULL, ",");
	newRecord.gpa = atof(pointer);
	return newRecord;
}

/*
* Read records from the input file and load student data into the hash table.
* hashTable: hash table containing student data
* filename: name of file containing student records
* 
* returns: nothing
*/
void processInputFile(struct student* hashTable[], char* filename)
{
	// Do not forget to use the following functions:
	// memset() - fill the buffer array with the specified character

	FILE* filePointer;
	char buffer[INPUT_BUF_SIZE];
	filePointer = fopen(filename, "r");
	if(filePointer != NULL)
	{
		printf("Hash Log\n");
		printf("----------------------------------------------------------\n");
		while(fgets(buffer, INPUT_BUF_SIZE, filePointer))
		{
			if(testRecord(buffer))
			{
				struct student newStudent = createStudent(buffer);
				if(testStudentData(newStudent))
				{
					insertStudent(hashTable, &newStudent);
				}
			}
			memset(buffer, '\0', sizeof(buffer));
		}
	}
	else
	{
		displayError(fileError, NULL);
	}
	fclose(filePointer);
}

/*
* Extra Credit: Search the student data contained in the hash table.
* hashTable: hash table containing student data
* filename: name of file containing search requests
*
* returns: nothing
*/
void processSearchFile(struct student* hashTable[], char* filename)
{
	// Do not forget to use the following functions:
	// strtok() - splits a string into separate parts
	// memset() - fill the buffer array with the specified character
	FILE* filePointer;
	char buffer[INPUT_BUF_SIZE];
	filePointer = fopen(filename, "r");
	if(filePointer != NULL)
	{
		char searchType[INPUT_BUF_SIZE];
		printf("\nSearch Results:\n");
		char searchString[INPUT_BUF_SIZE];
		printf("\nIndex  Name                  Number     Email Address      Credits  GPA\n");
					printf("-----  ------------------    ---------  -----------------  -------  ---\n");
		while(fgets(buffer, INPUT_BUF_SIZE, filePointer))
		{
			char* pointer;
			pointer = strtok(buffer, ",");
			strcpy(searchType, pointer);
			pointer = strtok(NULL, ",");
			strcpy(searchString, pointer);
			performSearch(hashTable, searchType, searchString);
			memset(buffer, '\0', sizeof(buffer));
		}
	}
	else
	{
		displayError(fileError, NULL);
	}
	fclose(filePointer);
}

/*
* Perform tests on the provided record to see if it is a valid record.
* record: String of student data
* 
* returns: true if no errors exists; otherwise, false
*/
bool testRecord(char record[])
{
	// Do not forget to use the following functions:
	// strcspn() - returns index of specified character a string
	// strncpy() - copies the specified number of characters between strings
	int endLine = strcspn(record, "\n");
	char trimmedError[endLine + 1];
	strncpy(trimmedError, record, endLine);
	trimmedError[endLine - 1] = '\0';

	if(record[0] == '\n' || record[0] == '\r')
	{
		displayError(blankRecord, trimmedError);
		return false;
	}
	if(endLine > 60 || endLine < 35)
	{
		displayError(shortRecord, trimmedError);
		return false;
	}
	int count = 0;
	for(int i = 0; i < endLine; ++i)
	{
		if(record[i] == ',')
		{
			count++;
		}
	}

	if(count != 4)
	{
		displayError(corruptRecord, trimmedError);
		return false;
	}
	return true;

}
