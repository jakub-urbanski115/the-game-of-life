life: main.o spr.o infiles.o
	$(CC) -o life main.o 
main.o: spr.h infiles.h
	$(CC) -c main.c 
spr.o: spr.h infiles.h 
	$(CC) -c spr.c rules.c 
infiles.o: infiles.h
	$(CC) -c infiles.c 

.PHONY: clean

clean:
	-rm *.o main spr infiles
