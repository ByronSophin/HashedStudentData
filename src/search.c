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
* Search the hash table for students using the provided search operation and query.
* hashTable: hash table containing student data
* searchType: type of search to perform
* searchString: query on which to perform the search
* 
* returns: nothing
*/
void performSearch(struct student* hashTable[], char* searchType, char* searchString)
{
	char* point;
	int searches;
	int searchInt;
	double gpa;
	searches = strtol(searchType, &point, 10);
	switch (searches) {
	case creditEqual:
		searchInt = strtol(searchString, &point, 10);
		printf("\nSearching Records Where Credits Is %d\n", searchInt);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] !=NULL && hashTable[i]->credits == searchInt)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case creditLess:
		searchInt = strtol(searchString, &point, 10);
		printf("\nSearching Records Where Credits < %d\n", searchInt);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] !=NULL && hashTable[i]->credits < searchInt)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case creditGreater:
		searchInt = strtol(searchString, &point, 10);
		printf("\nSearching Records Where Credits > %d\n", searchInt);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] !=NULL && hashTable[i]->credits > searchInt)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case emailKey:
		printf("\nSearching Records Where Email Is %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			int j = 0;
			if(hashTable[i] !=NULL)
			{
				while(compare == 0 && j < strlen(hashTable[i]->email))
				{
					if(hashTable[i]->email[j] != searchString[j])
					{
						 compare = -1;
					}
					++j;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	case emailContains:
		printf("\nSearching Records Where Email Contains %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			if(hashTable[i] !=NULL)
			{
				point = strstr(hashTable[i]->number, searchString);
				if(point == NULL)
				{
					 compare = -1;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}

		break;
	case nameFull:
		printf("\nSearching Records Where Full Name Is %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			int j = 0;
			if(hashTable[i] !=NULL)
			{
				while(compare == 0 && j < strlen(hashTable[i]->name))
				{
					if(hashTable[i]->name[j] != searchString[j])
					{
						 compare = -1;
					}
					++j;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	case nameFirst:
		printf("\nSearching Records Where First Name Is %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			int j = 0;
			if(hashTable[i] !=NULL)
			{
				char firstName[30];
				strcpy(firstName, hashTable[i]->name);
				char* pointer;
				pointer = strtok(firstName, " ");
				while(compare == 0 && j < strlen(pointer))
				{
					if(pointer[j] != searchString[j])
					{
						 compare = -1;
					}
					++j;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	case nameLast:
		printf("\nSearching Records Where Last Name Is %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			int j = 0;
			if(hashTable[i] !=NULL)
			{
				char firstName[30];
				strcpy(firstName, hashTable[i]->name);
				char* pointer;
				pointer = strtok(firstName, " ");
				pointer = strtok(NULL, " ");
				while(compare == 0 && j < strlen(pointer))
				{
					if(pointer[j] != searchString[j])
					{
						 compare = -1;
					}
					++j;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	case gpaEqual:
		gpa = atof(searchString);
		printf("\nSearching Records Where GPA Is %.1f\n", gpa);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] != NULL && hashTable[i]->gpa == gpa)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case gpaLess:
		gpa = atof(searchString);
		printf("\nSearching Records Where GPA < %.1f\n", gpa);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] != NULL && hashTable[i]->gpa < gpa)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case gpaGreater:
		gpa = atof(searchString);
		printf("\nSearching Records Where GPA > %.1f\n", gpa);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			if(hashTable[i] != NULL && hashTable[i]->gpa > gpa)
			{
				displayRecord(hashTable[i], i);
			}

		}
		break;
	case numberKey:
		printf("\nSearching Records Where Number Is %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			int j = 0;
			if(hashTable[i] !=NULL)
			{
				while(compare == 0 && j < strlen(hashTable[i]->number))
				{
					if(hashTable[i]->number[j] != searchString[j])
					{
						 compare = -1;
					}
					++j;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	case numberContains:
		printf("\nSearching Records Where Number Contains %s\n", searchString);
		for(int i = 0; i < TABLE_SIZE; i++)
		{
			int compare = 0;
			if(hashTable[i] !=NULL)
			{
				point = strstr(hashTable[i]->number, searchString);
				if(point == NULL)
				{
					 compare = -1;
				}
				if(compare == 0)
				{
					displayRecord(hashTable[i], i);
				}
			}
		}
		break;
	}
}
