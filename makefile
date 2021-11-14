all: work15.o
	gcc -o program work15.o

work15.o: work15.c
	gcc -c work15.c

run:
	./program

clean:
	rm *.o