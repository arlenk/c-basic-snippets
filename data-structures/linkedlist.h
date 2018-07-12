#include <stdlib.h>
#include <stdio.h>

typedef struct ListItem
{
	void *value;
	struct ListItem *next;
} ListItem;

ListItem *ListCreate(void *value);
ListItem *ListAppend(ListItem *list, void *value);