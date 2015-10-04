COMPILER = gcc
CCFLAGS  = -Wall -ansi -pedantic
all: libsl.a main

libsl.a: sorted-list.o
	ar cr libsl.a sorted-list.o
main: main.o
	$(COMPILER) $(CCFLAGS) -o s1 main.o
main.o: main.c
	$(COMPILER) $(CCFLAGS) -c main.c 
	
	
clean:
	rm -f main main.o