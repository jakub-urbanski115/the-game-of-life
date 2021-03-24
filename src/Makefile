CC = gcc
CFLAGS = -g -Wall
OBJECTS = main.o spr.o infiles.o outfiles.o rules.o gifenc.o
TARGET = life 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

#main.o: main.c spr.h infiles.h
#	$(CC) $(CFLAGS) -c main.c

#infiles.o: infiles.c infiles.h
#	$(CC) $(CFLAGS) -c infiles.c
	
#spr.o: spr.c spr.h
#	$(CC) $(CFLAGS) -c spr.c

#rules.o: rules.c spr.h
#	$(CC) $(CFLAGS) -c rules.c

#gifenc.o: gifenc.c gifenc.h
#	$(CC) $(CFLAGS) -c gifenc.c





.PHONY: clean

clean:
	-rm -f $(OBJECTS) $(TARGET)
