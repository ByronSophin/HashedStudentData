Description: Project 1 reads an input file of the csv format and breaks apart each line by commas.
Each broken element is a specific data about a student and is used to create a new student structure of these
elements. The student structures that form from each line is placed into a hash table and the program prints a
hash log of every student added to the hash table and the contents of the hash table after the file has been 
fully read. The project also handles and prints various errors such as having a wrong file name or having the 
wrong student number format. The project also provides a search feature where a file name is added as a second
argument and with the correct commands, can search and return student data from the hash table.

Extra Credit: ATTEMPTED

Experience: The most challenging part of the project was at the beginning of development and trying to understand
what each file and method needs to do. Furthermore, it was difficult to test the progress of the project when many
of the c files and methods overlapped and worked together. After the initial confusion, the project was not that  
difficult, as the methods and algorithms were not complex and would at most require some googling for what an 
unfamiliar function like strcspn() does. While not complicated, some of the functions like performSearch() 
required a decent amount of time to complete from just the sheer amount of things it needed to do for different cases.

Shortcomings: No shortcomings exist.

Improvements: My performSearch() function is incredibly long because it has code to complete a different search operation
in each switch case where some of which is repetitive like the for loop iterating through the hash table. This could be
solved by having another function that handles repetitive tasks, and calling it in the switch cases instead.