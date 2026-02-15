#include "List.h"

#include <stddef.h>
#include <stdlib.h>

struct List {
    size_t length;
    size_t capacity;
    void **items;
};

List List_create(void) {
    List l = malloc(sizeof(struct List));
    size_t length = 0;
    size_t capacity = 8;

    l->length = length;
    l->items = malloc(capacity * sizeof(void *));

    return l;
}

void List_destroy(List l) {
    if (l == NULL) {
        free(l);
        return;
    }

    free(l->items);
    free(l);

    return;
}

size_t List_getLength(List l) { return l->length; }
void List_setLength(List l, size_t length) {
    l->length = length;
    return;
}

size_t List_getCapacity(List l) { return l->capacity; }
void List_setCapacity(List l, size_t capacity) {
    l->capacity = capacity;
    return;
}
