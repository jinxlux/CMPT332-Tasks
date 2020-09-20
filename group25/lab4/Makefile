#    NAME: Xudong Li
#    NSID:xul395
#    Student Number:11206927

#    NAME:Tong Wang   
#    NSID: tow087 
#    Student Number: 11201222
#    CMPT 332 Term 1 2019

#    NAME: Enyu Ma
#    NSID:enm614
#    Student Number:11191666

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
ARCH = $(shell uname -sm | tr -d ' ')
LIBPATH = /student/cmpt332/pthreads/lib/$(ARCH)
HEADPATH = /student/cmpt332/pthreads
.PHONY: all clean 
all: santasynch

santasynch.o: Lab4.synchproblem.c
	$(CC) -o santasynch.o -c $(CPPFLAGS) $(CFLAGS) Lab4.synchproblem.c -I$(HEADPATH)
testsantasynch.o: Lab4.testsynchproblem.c
	$(CC) -o testsantasynch.o -c $(CPPFLAGS) $(CFLAGS) Lab4.testsynchproblem.c -I$(HEADPATH)
santasynch: santasynch.o testsantasynch.o
	$(CC) -o santasynch santasynch.o testsantasynch.o -lpthreads -L$(LIBPATH)

clean:
	rm -f *.o *.a santasynch