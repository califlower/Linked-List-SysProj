COMPILER = gcc
CCFLAGS  = -Wall -ansi -pedantic
all: main

main: main.o
	$(COMPILER) $(CCFLAGS) -o s1 main.o
main.o: main.c
	$(COMPILER) $(CCFLAGS) -c main.c 
clean:
	rm -f main main.o