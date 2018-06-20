#include <stdlib.h>
#include <stdio.h>

typedef struct ListItem
{
	void *value;
	struct ListItem *next;
} ListItem;

ListItem *ListCreate(void *value)
{
	ListItem *item = (ListItem *) malloc(sizeof(ListItem));
	item->value = value;
	item->next = NULL;

	return item;
}

ListItem *ListAppend(ListItem *list, void *value)
{
	ListItem *item = (ListItem *) malloc(sizeof(ListItem));
	item->value = value;
	item->next = list;

	return item;
}


int main(void)
{
	int i = 3;
	int j = 4;

	ListItem *list = ListCreate(&i);
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
}