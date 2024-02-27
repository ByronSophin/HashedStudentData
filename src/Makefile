create : main.o errors.o student.o hashtable.o search.o
	gcc -o create main.o errors.o student.o hashtable.o search.o
main.o : main.c headers.h
	gcc -c main.c
errors.o : errors.c headers.h errors.h
	gcc -c errors.c
student.o : student.c headers.h student.h
	gcc -c student.c
hashtable.o : hashtable.c headers.h hashtable.h
	gcc -c hashtable.c
search.o : search.c headers.h search.h
	gcc -c search.c
clean:
	rm create main.o errors.o student.o hashtable.o search.o