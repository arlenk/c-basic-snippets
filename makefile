CFLAGS=-g -Wall -Imodels -Idata-structures
CC=gcc
OBJECTS=linkedlist.o

mailing_addresses: programs/mailing_addresses.c models/mailing_address.h linkedlist.o
	$(CC) $(CFLAGS) -o mailing_addresses programs/mailing_addresses.c $(OBJECTS)

linkedlist.o: data-structures/data-structures.h data-structures/linkedlist.c
	$(CC) $(CFLAGS) -c data-structures/linkedlist.c

array.o: data-structures/data-structures.h data-structures/array.c
	$(CC) $(CFLAGS) -c data-structures/array.c

