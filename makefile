all: myapp

# Which compiler
CC = gcc

# Where are include files kept
INCLUDE = .

# Options for development
CFLAGS = -g -Wall -ansi

# Options for release
# CFLAGS = -O -Wall -ansi -lrt

# Linux Program.
#L_FILES = main703.o
L_FILES = main.o \
			main310.o main311.o main312.o \
			main801.o main802.o
#			main601.o main602.o main603.o \
#			main701.o main702.o main703.o main704.o main705.o main706.o main707.o \
#			main1001.o

myapp: $(L_FILES)
		$(CC) -o myapp $(L_FILES)

main.o: main.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.c

# Linux Program chapter03. 
main310.o: main310.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main310.c
main311.o: main311.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main311.c
main312.o: main312.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main312.c
	
# Linux Program chapter06. 
main601.o: main601.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main601.c
main602.o: main602.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main602.c
main603.o: main603.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main603.c	
	
# Linux Program chapter07. 
main701.o: main701.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main701.c
main702.o: main702.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main702.c
main703.o: main703.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main703.c
main704.o: main704.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main704.c
main705.o: main705.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main705.c
main706.o: main706.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main706.c
main707.o: main707.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main707.c
	
# Linux Program chapter08. 
main801.o: main801.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main801.c
main802.o: main802.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main802.c
	
# Linux Program chapter10.
main1001.o: main1001.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main1001.c
main1010.o: main1010.c
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main1010.c

clean:
	rm -rf $(L_FILES) myapp
