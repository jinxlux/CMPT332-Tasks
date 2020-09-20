# CMPT 332 Fall 2018
# NAME: Kai Langen/Dwight Makaroff
# NSID: protected
# Student number: protected
# Makefile for Lab 3


CC=gcc 
CFLAGS=-std=gnu90 -Wall -pedantic -g -O0
LFLAGS=-std=gnu90 -O0 
BUILD=./build

.PHONY: all clean

all: $(BUILD) program

$(BUILD):
	mkdir -p $(BUILD)

program: $(BUILD)/program.o
	$(CC) $(LFLAGS) -o program $(BUILD)/program.o

$(BUILD)/program.o: program.c
	$(CC) $(CFLAGS) -c program.c -o $(BUILD)/program.o -I.

clean:
	rm -rf $(BUILD) program
