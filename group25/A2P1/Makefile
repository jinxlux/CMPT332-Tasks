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
RTTTHREAD = /student/cmpt332/rtt
.PHONY: all clean B C


all: B C
B: reader-writer-test
C: s-chat

#part B
#$TARGET

Monitor.o: Monitor.c 
	$(CC) -o Monitor.o -c $(CPPFLAGS) $(CFLAGS) Monitor.c -I$(HEADPATH) -I.
list_adders.o: list_adders.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^
list_movers.o: list_movers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_movers.c
list_removers.o: list_removers.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) list_removers.c
liblist.a: list_movers.o list_adders.o list_removers.o
	ar rcs liblist.a list_movers.o list_adders.o list_removers.o
libMonitor.a: Monitor.o
	ar rcs libMonitor.a Monitor.o
rwMonitor.o: reader-writer-monitor.c
	$(CC) -o rwMonitor.o -c $(CPPFLAGS) $(CFLAGS) reader-writer-monitor.c -I.
rw.o: reader-writer.c
	$(CC) -o rw.o -c $(CPPFLAGS) $(CFLAGS) reader-writer.c -I. -I$(HEADPATH)
reader-writer-test: rwMonitor.o rw.o libMonitor.a liblist.a
	$(CC) -o reader-writer-test $(CFLAGS) $(CPPFLAGS) rwMonitor.o rw.o -L. -L$(LIBPATH) -llist -lMonitor -lpthreads

#part C
#$TARGET

s-chat.o: s-chat.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) s-chat.c -I$(RTTTHREAD)/include 
s-chat: s-chat.o
	$(CC) -o s-chat $(CFLAGS) $(CPPFLAGS)  s-chat.o -L$(RTTTHREAD)/lib/$(ARCH) -lRtt -lRttUtils -ltirpc
clean:
	rm -f *.o *.a reader-writer-test s-chat


