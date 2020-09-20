# Tong Wang tow087 11201222

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic

.PHONEY:  unix windows all sample-thread
all: sample-thread
ARCH = $(shell uname -sm | tr -d ' ')
ifneq (,$(findstring MINGW,$(ARCH)))

sample-thread: thread_windows.exe

wthread.o: wthread.c
		$(CC) -o wthread.o -c $(CPPFLAGS) $(CFLAGS) wthread.c
thread_windows.o: thread.c
		$(CC) -o thread_windows.o -c $(CPPFLAGS) $(CFLAGS) thread.c
thread_windows.exe: wthread.o thread_windows.o
		$(CC) -o thread_windows.exe  $(CPPFLAGS) $(CFLAGS) wthread.o thread_windows.o

else

sample-thread: sample-linux

sample-linux.o: sample-linux.c
		$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -I.
linux-lib.o: linux-lib.c
		$(CC) -o linux-lib.o -c $(CPPFLAGS) $(CFLAGS) linux-lib.c -I.
liblin.a: linux-lib.o		
		ar rcs liblin.a linux-lib.o
sample-linux: sample-linux.o liblin.a
		$(CC) -o sample-linux  $(CPPFLAGS) $(CFLAGS) sample-linux.o -L. -llin
endif
clean:
	rm -rf *.o	*.exe liblin.a sample-thread