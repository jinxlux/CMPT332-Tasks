	# NAME: Xudong Li
	# NSID:xul395
	# Student Number:11206927


	# NAME:Tong Wang   
	# NSID: tow087 
	# Student Number: 11201222
	# CMPT 332 Term 1 2019
   
    # group: 25


CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
ARCH = $(shell uname -sm | tr -d ' ')
LIBPATH = /student/cmpt332/pthreads/lib/$(ARCH)
HEADPATH = /student/cmpt332/pthreads
.PHONY: all clean sim

all: sim 
list_adders.o: list_adders.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^
list_movers.o: list_movers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_movers.c
list_removers.o: list_removers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_removers.c
liblist.a: list_movers.o list_adders.o list_removers.o
	ar rcs liblist.a list_movers.o list_adders.o list_removers.o
sim.o: sim.c
	$(CC) -o sim.o -c $(CPPFLAGS) $(CFLAGS) sim.c -I$(HEADPATH)
sim: sim.o liblist.a
	$(CC) -o sim sim.o -lpthreads -L$(LIBPATH) -llist -L.

clean:
	rm -f *.o *.a sim