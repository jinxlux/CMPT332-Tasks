#  NAME: Xudong Li
#  NSID:xul395
#  Student Number:11206927


# 	NAME:Tong Wang   
#   NSID: tow087 
#   Student Number: 11201222
#   CMPT 332 Term 1 2019

#   group25

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
ARCH = $(shell uname -sm | tr -d ' ')
LIBPATH = /student/cmpt332/pthreads/lib/$(ARCH)
HEADPATH = /student/cmpt332/pthreads
.PHONY: all clean PartE

#part A1

ifneq (,$(findstring MINGW,$(ARCH)))
all: allA 
allA: partA1
square.o: square.c
	$(CC) -o square.o -c $(CPPFLAGS) $(CFLAGS)  square.c
partA1.o: partA1.c
	$(CC) -o partA1.o -c $(CPPFLAGS) $(CFLAGS) PartA1.c
partA1: partA1.o square.o
	$(CC) -o partA1 $(CPPFLAGS) $(CFLAGS) partA1.o square.o

else
#$TARGET
all: C A2 PartE C1
C: mytestlist-Linuxx86_64 
C1: testlist-Linuxx86_64
A2: partA2
#Part A2
square.o: square.c
	$(CC) -o square.o -c $(CPPFLAGS) $(CFLAGS)  square.c
partA2.o: partA2.c
	$(CC) -o partA2.o -c $(CPPFLAGS) $(CFLAGS) partA2.c -I$(HEADPATH)
partA2: partA2.o square.o
	$(CC) -o partA2 partA2.o square.o -lpthreads -L$(LIBPATH)
#Part C mytestlist
list_adders.o: list_adders.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^
list_movers.o: list_movers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_movers.c
list_removers.o: list_removers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_removers.c
liblist.a: list_movers.o list_adders.o list_removers.o
	ar rcs liblist.a list_movers.o list_adders.o list_removers.o
mytestlist.o: mytestlist.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) mytestlist.c
mytestlist-Linuxx86_64: mytestlist.o liblist.a
	$(CC) -o mytestlist-Linuxx86_64 $(CFLAGS) $(CPPFLAGS) mytestlist.o -L. -llist
#part D
#part E
PartE: partE
partE.o: partE.c
	$(CC) -o partE.o -c  $(CFLAGS) $(CPPFLAGS) partE.c
partE: partE.o
	$(CC) -o partE $(CFLAGS) $(CPPFLAGS) partE.o

#Part C testlist
testlist.o: testlist.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) testlist.c
testlist-Linuxx86_64: testlist.o liblist.a
	$(CC) -o testlist-Linuxx86_64 $(CFLAGS) $(CPPFLAGS) testlist.o -L. -llist
endif
clean:
	rm -f *.o *.a mytestlist-Linuxx86_64 partA1.exe partA2 partE testlist-Linuxx86_64

