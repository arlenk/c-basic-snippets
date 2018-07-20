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


LinkedList *ListCreate();
void ListAppend(LinkedList *list, void *value);