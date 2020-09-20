# Tong Wang tow087 11201222

CC = gcc
CFLAGS = -g
CPPFLAGS = -std=gnu90 -Wall -pedantic
ARCH = $(shell uname -sm | tr -d ' ')
LIBPATH = /student/cmpt332/pthreads/lib/$(ARCH)
HEADPATH = /student/cmpt332/pthreads
CROSS_COMPILE = arm-linux-gnueabi-

.PHONY:  unix windows all sample-thread
all: sample-thread app

ifneq (,$(findstring MINGW,$(ARCH)))

sample-thread: thread_windows.exe

wthread.o: wthread.c
		$(CC) -o wthread.o -c $(CPPFLAGS) $(CFLAGS) wthread.c
thread_windows.o: thread.c
		$(CC) -o thread_windows.o -c $(CPPFLAGS) $(CFLAGS) thread.c
thread_windows.exe: wthread.o thread_windows.o
		$(CC) -o thread_windows.exe wthread.o thread_windows.o

else

sample-thread: sample-linux app raspi-sample

sample-linux.o: sample-linux.c
		$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -I.
linux-lib.o: linux-lib.c
		$(CC) -o linux-lib.o -c $(CPPFLAGS) $(CFLAGS) linux-lib.c -I.
liblin.a: linux-lib.o		
		ar rcs liblin.a linux-lib.o
sample-linux: sample-linux.o liblin.a
		$(CC) -o sample-linux  sample-linux.o -L. -llin
# app make part
app.o: app.c
		$(CC) -o app.o -c $(CPPFLAGS) $(CFLAGS) app.c -I$(HEADPATH)
app: app.o
		$(CC) -o app app.o -lpthreads -L$(LIBPATH)
# cross compliling
raspi-lib.o: linux-lib.c
		$(CROSS_COMPILE)$(CC) -o raspi-lib.o -c $(CPPFLAGS) $(CFLAGS) linux-lib.c -I.
sample-raspi.o: sample-linux.c
		$(CROSS_COMPILE)$(CC) -o sample-raspi.o -c $(CPPFLAGS) $(CFLAGS) sample-linux.c -I.
libraspi.a: raspi-lib.o
		$(CROSS_COMPILE)ar rcs libraspi.a raspi-lib.o
raspi-sample: sample-raspi.o libraspi.a
		$(CROSS_COMPILE)$(CC) -o raspi-sample sample-raspi.o -L. -lraspi

endif
clean:
	rm -rf *.o *.a *.exe sample-linux app raspi-sample