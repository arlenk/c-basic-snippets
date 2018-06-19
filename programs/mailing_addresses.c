#include <stdio.h>
#include <string.h>
#include <mailing_address.h>

#define LINE_BUFFER_SIZE 2048 /* max line length we can read in */

int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		return 1;
	}
	char *input_file = argv[1];
	printf("reading data from %s\n\n", input_file);
	int i = 0;

	FILE *input = fopen(input_file, "r");
	Address address;

	char line[LINE_BUFFER_SIZE];

	while (fgets(line, LINE_BUFFER_SIZE, input))
	{
		// fscanf(input, "%d|%s|%s|%s|%s|%s|%s|%s|%d") == 9)
		/* ignore header row */
		if (i > 0) 
		{
			if (i % 100 == 0)
			{
				printf("%s\n", line);
				printf("%lu\n", strlen(line));
				char *token;
				char *rest = NULL;

				token = strtok_r(line, "|", &rest);
				while (token != NULL)
				{
					printf("token: %s\n", token);
					printf("%s\n", line);
					token = strtok_r(NULL, "|", &rest);
				}
			}		
		}
		i++;
	}
	printf("read %d rows\n", i);
	return 0;	
}