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
.PHONY: all clean sim

all: sim 
sim.o: sim.c
	$(CC) -o sim.o -c $(CPPFLAGS) $(CFLAGS) sim.c 
sim: sim.o 
	$(CC) -o sim sim.o -lm

clean:
	rm -f *.o *.a sim