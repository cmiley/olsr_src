OBJS = olsr_classes.o link_parser.o
CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: test

test: olsr_classes.o olsr_test.cpp link_parser.o
	$(CC) $(LFLAGS) $(OBJS) olsr_test.cpp -o test -lcurl

olsr_classes.o: olsr_classes.h olsr_classes.cpp
	$(CC) $(CFLAGS) olsr_classes.cpp

link_parser.o: link_parser.h link_parser.cpp
	$(CC) $(CFLAGS) link_parser.cpp

clean:
	rm *.o test