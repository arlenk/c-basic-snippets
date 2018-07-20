#include <stdlib.h>
#include <stdio.h>
#include <linkedlist.h>


LinkedList *ListCreate()
{
	LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
	list->size = 0;
	list->head = NULL;

	return list;
}

void ListAppend(LinkedList *list, void *value)
{
	ListItem *item = (ListItem *) malloc(sizeof(ListItem));
	item->value = value;
	item->next = list->head;

	list->head = item;
	list->size++;

	return;
}

/*
int main(void)
{
	int i = 3;
	int j = 4;

	//	ListItem *list = ListCreate(&i);
    ListItem *list = NULL;
    list = ListAppend(list, &i);
	list = ListAppend(list, &j);

	i = 0;
	ListItem *item = list;
	while (item != NULL)
	{
		int *value = (int *) item->value;
		printf("item %d: %d\n", i, *value);
		i++;
		item = item->next;
	}

	return 0;
}*/