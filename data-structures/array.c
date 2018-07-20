#include <stdlib.h>
#include <stdio.h>
#include <data-structures.h>


Array *ArrayCreate()
{
	Array *array = malloc(sizeof(Array));
	array->allocated_size = 10;
	array->used_size = 0;
	array->items = malloc(10 * sizeof(void *));

	return array;
}

void ArrayAppend(Array *array, void *value)
{
	// check if array if large enough first
	if (array->allocated_size == array->used_size)
	{
		int new_size = array->allocated_size * 2;
		printf("resizing array from %ud to %ud", array->used_size, new_size);
		//array->items = realloc(array->items, new_size * sizeof(void *));
		array->allocated_size = new_size;
	}
	array->items[array->used_size++] = value;
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