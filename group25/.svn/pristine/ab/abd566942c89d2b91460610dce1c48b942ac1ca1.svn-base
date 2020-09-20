#  NAME: Xudong Li
#  NSID:xul395
#  Student Number:11206927


CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
ARCH = $(shell uname -sm | tr -d ' ')
LIBPATH = /student/cmpt332/pthreads/lib/$(ARCH)
HEADPATH = /student/cmpt332/pthreads
.PHONY: all clean B


all: B
B: reader-writer-test

#part B
#$TARGET

Monitor.o: monitor.c 
	$(CC) -o Monitor.o -c $(CPPFLAGS) $(CFLAGS) monitor.c -I$(HEADPATH) 
rwMonitor.o: reader-writer-monitor.c
	$(CC) -o rwMonitor.o -c $(CPPFLAGS) $(CFLAGS) reader-writer-monitor.c -I. -I$(HEADPATH) 
rw.o: reader-writer.c
	$(CC) -o rw.o -c $(CPPFLAGS) $(CFLAGS) reader-writer.c -I. -I$(HEADPATH)
reader-writer-test: rwMonitor.o rw.o Monitor.o liblist.a
	$(CC) -o reader-writer-test $(CFLAGS) $(CPPFLAGS) rwMonitor.o rw.o Monitor.o -L. -L$(LIBPATH) -llist -lpthreads


clean:
	rm -f *.o reader-writer-test 


