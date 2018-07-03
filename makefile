CFLAGS=-g -Wall -Imodels
CC=clang

mailing_addresses: programs/mailing_addresses.c models/mailing_address.h
	$(CC) $(CFLAGS) -o emailing_addresses programs/mailing_addresses.c

