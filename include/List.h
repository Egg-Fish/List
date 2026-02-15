#pragma once

#include <stddef.h>

typedef struct List *List;

List List_create(void);
List List_createFromItems(void **items, size_t itemsLength);
void List_destroy(List l);

size_t List_getLength(List l);
size_t List_getCapacity(List l);

void *List_getItemAtIndex(List l, size_t index);

void List_appendItem(List l, void *item);
