#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mailing_address.h>
#include <linkedlist.h>

#define LINE_BUFFER_SIZE 2048 /* max line length we can read in */

Address *parseline(char *line);
void print_mailing_address(Address);
void read_mailing_addresses(char *input_file, LinkedList **list);

/* convert a line of text into Address 
*/
Address *parseline(char *line)
{
	Address *address = (Address *) malloc(sizeof(Address));	
	char *token;
	char *rest = NULL;
	char *end = NULL;
	
	// each line is id, first name, last name, email,
	// gender, street address, city, state, zip

	// id
	token = strtok_r(line, "|", &rest);
	address->id = (int) strtol(token, &end, 10);

	// first name
	token = strtok_r(NULL, "|", &rest);
	address->first_name = strdup(token);

	// last name
	token = strtok_r(NULL, "|", &rest);
	address->last_name = strdup(token);

	// email
	token = strtok_r(NULL, "|", &rest);
	address->email = strdup(token);

	// gender
	token = strtok_r(NULL, "|", &rest);
	address->gender = strdup(token);

	// street address
	token = strtok_r(NULL, "|", &rest);
	address->address = strdup(token);

	// city
	token = strtok_r(NULL, "|", &rest);
	address->city = strdup(token);

	// state
	token = strtok_r(NULL, "|", &rest);
	address->state = strdup(token);

	// zip
	token = strtok_r(NULL, "|", &rest);
	address->zip = strdup(token);

	return address;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("must provide data file as input\n");
		return 1;
	}

	char *input_file = argv[1];
	printf("reading data from %s\n\n", input_file);

	LinkedList *address_book = ListCreate();
	read_mailing_addresses(input_file, &address_book);
    printf("address book has %d entries\n", address_book->size);


	int i = 0;
	ListItem *address = address_book->head;
	while (address != NULL)
	{
		if (i % 100 == 0)
		{
			print_mailing_address(*(Address *) address->value);
		}
		address = address->next;
		i++;
	}


	return 0;	
}


void read_mailing_addresses(char *input_file, LinkedList **list)
{
	FILE *input = fopen(input_file, "r");
	int i = 0;
	char line[LINE_BUFFER_SIZE];


	while (fgets(line, LINE_BUFFER_SIZE, input))
	{
		/* ignore header row */
		if (i == 0)
		{
			i++;
			continue;
		}
		Address *address = parseline(line);
	
		ListAppend(*list, address);
		i++;
	}

	printf("read %d rows\n", i);
	fclose(input);
}


void print_mailing_address(Address address)
{
	printf("%s %s [%d]\n", address.first_name, address.last_name, address.id);
	printf("%s\n", address.address);
	printf("%s, %s %s\n", address.city, address.state, address.zip);
	printf("\n");
}