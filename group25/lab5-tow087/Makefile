


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
RTTTHREAD = /student/cmpt332/rtt
.PHONY: all clean B


all: B 
B: reader-writer-test

#part B
#$TARGET

Monitor.o: monitor.c 
	$(CC) -o Monitor.o -c $(CPPFLAGS) $(CFLAGS) monitor.c -I$(HEADPATH) -I.
rwMonitor.o: reader-writer-monitor.c
	$(CC) -o rwMonitor.o -c $(CPPFLAGS) $(CFLAGS) reader-writer-monitor.c -I. -I$(HEADPATH)
rw.o: reader-writer.c
	$(CC) -o rw.o -c $(CPPFLAGS) $(CFLAGS) reader-writer.c -I. -I$(HEADPATH)
reader-writer-test: rwMonitor.o rw.o liblist.a Monitor.o
	$(CC) -o reader-writer-test $(CFLAGS) $(CPPFLAGS) rwMonitor.o rw.o Monitor.o -L. -L$(LIBPATH) -llist -lpthreads

clean:
	rm -f *.o reader-writer-test 

