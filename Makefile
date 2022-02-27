# -*- Makefile -*-

# target: dependencies
# 	action

all: hashtable

hashtable: hashtable.o 
	g++ hashtable.o -o hashtable

hashtable.o: hashtable.cpp element.cpp
	g++ -c hashtable.cpp 

element.o: element.cpp
	g++ -c element.cpp 

clean:
	rm -f *.o hashtable

