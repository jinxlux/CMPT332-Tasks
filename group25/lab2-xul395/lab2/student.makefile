# makefile for UBC pthreads
# Maintained by Dwight Makaroff, University of Saskatchewan
# Last modified Sep 22, 2016
#
#CC      = cc    # use CC for hpux
CC     = gcc   # use gcc otherwise


PLATFORM = $(shell uname -s)
ifeq ($(PLATFORM), solaris)
ARCH = $(PLATFORM)
else
ARCH = $(shell uname -m)
endif


CFLAGS =  -Wall -g -D$(ARCH)                    # defines otherwise

ifeq ($(ARCH), sun4u)
  ASM_ARCH=solaris
else
  ASM_ARCH = $(ARCH)
endif


CPP = /usr/bin/cpp

#change these if your application code is not in the same
# directory as the pthreads library.
INCLUDEDIR=.
LIBDIR=lib

app:    app.o $(LIBDIR)/$(PLATFORM)$(ARCH)/libpthreads.a 
	$(CC) $(CFLAGS) app.o -L$(LIBDIR)/$(PLATFORM)$(ARCH) -lpthreads -o app

$(LIBDIR)/$(PLATFORM)$(ARCH)/libpthreads.a: startup.o context.o queue.o procMgmt.o ipc.o time.o scheduling.o synch.o mem.o
	ar rc libpthreads.a startup.o context.o queue.o procMgmt.o ipc.o time.o scheduling.o synch.o mem.o
	ranlib libpthreads.a
	chmod 644 libpthreads.a
	mv libpthreads.a lib/$(PLATFORM)$(ARCH)

kernel.h: standards.h os.h kernelTypes.h ipc.h ptime.h procMgmt.h mem.h synch.h scheduling.h queue.h kernelConfig.h
#	touch kernel.h

app.o: app.c os.h standards.h
	$(CC) $(CFLAGS)  -c app.c -I$(INCLUDEDIR)

synch.o:  synch.c kernel.h os.h
	$(CC) $(CFLAGS)  -c synch.c -o synch.o

scheduling.o:  scheduling.c kernel.h
	$(CC) $(CFLAGS)  -c scheduling.c -o scheduling.o

procMgmt.o:  procMgmt.c kernel.h
	$(CC) $(CFLAGS)  -c procMgmt.c -o procMgmt.o

queue.o:  queue.c kernel.h
	$(CC) $(CFLAGS)  -c queue.c -o queue.o

ipc.o:  ipc.c kernel.h
	$(CC) $(CFLAGS) -c ipc.c -o ipc.o

time.o:  time.c kernel.h
	$(CC) $(CFLAGS)  -c time.c -o time.o

mem.o:  mem.c kernel.h
	$(CC) $(CFLAGS)  -c mem.c -o mem.o

startup.o:  startup.c kernel.h
	$(CC) $(CFLAGS)  -c startup.c -o startup.o

context.o: context.S
	$(CPP) -D$(PLATFORM) -D$(ASM_ARCH) -P context.S > _context.S
	$(CC) -D$(ARCH) -g  -c -o context.o _context.S
	rm _context.S

clean:
	rm *.o lib/$(PLATFORM)$(ARCH)/*.a app 
