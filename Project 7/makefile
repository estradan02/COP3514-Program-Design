store: store.o items.o
	gcc -Wall -o store store.c items.c
store.o: items.h store.c
	gcc -c store.c
items.o: items.c items.h
	gcc -c items.c
clean:
	rm store.o items.o store
