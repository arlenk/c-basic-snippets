#include <stdlib.h>
#include <stdio.h>

typedef struct ListItem
{
	void *value;
	struct ListItem *next;
} ListItem;

typedef struct
{
	int size;
	ListItem *head;
} LinkedList;

typedef struct 
{
	void *items;
	int allocated_size;
	int used_size;
} Array;

LinkedList *ListCreate();
void ListAppend(LinkedList *list, void *value);

Array *ArrayCreate();
void ArrayAppend(Array *array, void *value);