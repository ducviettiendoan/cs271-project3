# -*- Makefile -*-

# target: dependencies
# 	action

all: test_hashtable

test_hashtable: test_hashtable.o
	g++ test_hashtable.o -o test_hashtable

test_hashtable.o: test_hashtable.cpp hashtable.cpp
	g++ -c test_hashtable.cpp

hashtable: hashtable.o 
	g++ hashtable.o -o hashtable

hashtable.o: hashtable.cpp element.cpp
	g++ -c hashtable.cpp 

element.o: element.cpp
	g++ -c element.cpp 

clean:
	rm -f *.o test_hashtable

