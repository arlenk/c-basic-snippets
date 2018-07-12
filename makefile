CFLAGS=-g -Wall -Imodels -Idata-structures
CC=clang
OBJECTS=linkedlist.o

mailing_addresses: programs/mailing_addresses.c models/mailing_address.h
	$(CC) $(CFLAGS) -o mailing_addresses programs/mailing_addresses.c $(OBJECTS)

linkedlist.o: data-structures/linkedlist.h data-structures/linkedlist.c
	$(CC) $(CFLAGS) -c data-structures/linkedlist.c
