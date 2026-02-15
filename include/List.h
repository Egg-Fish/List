#pragma once

#include <stddef.h>

typedef struct List *List;

List List_create(void);
void List_destroy(List l);

size_t List_getLength(List l);
size_t List_getCapacity(List l);
