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
#define HASH_TABLE_SEGMENTS 7 // Value used in the computeHash() function
#define MOD_SIZE 5 // Modulus value to use in the computeHash() function

/*
* Compute a hash value using the student name value
* studentName: name of student
* 
* returns: computed hash value
*/
int computeHash(char* studentName)
{
	int sum = 0;
	for(int i = 0; i < sizeof(studentName); i++)
	{
		sum = sum + studentName[i];
	}
	return sum % MOD_SIZE * HASH_TABLE_SEGMENTS;
}

/*
* Display the student data stored in the hash table.
* hashTable: hash table containing student data
* 
* returns: nothing
*/
void displayHashTable(struct student* hashTable[])
{
	printf("Hash Table Contents\n");
	printf("-------------------\n\n");
	printf("Index  Name                  Number     Email Address      Credits  GPA\n");
			printf("-----  ------------------    ---------  -----------------  -------  ---\n");
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		if(hashTable[i] != NULL)
		{
			displayRecord(hashTable[i], i);
		}

	}

}

/*
* Initialize each element in the hash table to NULL.
* hashTable: hash table containing student data
* 
* returns: nothing
*/
void initializeTable(struct student* hashTable[])
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

/*
* Insert a student's data into the hash table.
* hashTable: hash table containing student data
* temp: student whose data will be inserted
* 
* returns: nothing
*/
void insertStudent(struct student* hashTable[], struct student* temp)
{
	int hashValue = computeHash(temp->name);
	int newIndex = hashValue;
	if(hashTable[hashValue] != NULL)
	{
		while(hashTable[newIndex] != NULL)
		{
			++newIndex;
		}
	}
	hashTable[newIndex] = (struct student*)malloc(sizeof(struct student));
	strcpy(hashTable[newIndex]->name, temp->name);
	strcpy(hashTable[newIndex]->number, temp->number);
	strcpy(hashTable[newIndex]->email, temp->email);
	hashTable[newIndex]->gpa = temp->gpa;
	hashTable[newIndex]->credits = temp->credits;
	printf("Added Student to Hash Table: %-20s Target %2d, Actual %2d\n", hashTable[newIndex]->name, hashValue, newIndex);



	// Do not forget to use the malloc() function to reserve space for the student structure
	// Do not forget to use the strcpy() function to store the string data in the hash table

}
