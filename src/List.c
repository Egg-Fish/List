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

const void **List_getItems(List l) { return (const void **)l->items; }
void List_setItems(List l, void **items) {
    l->items = items;
    return;
}

void List_appendItem(List l, void *item) {
    size_t length = List_getLength(l);
    size_t capacity = List_getCapacity(l);

    if (length >= capacity) {
        capacity *= 2;
        void **oldItems = (void **)List_getItems(l);
        void **newItems = realloc(oldItems, capacity * sizeof(void *));
        List_setCapacity(l, capacity);
        List_setItems(l, newItems);
    }

    void **items = (void **)List_getItems(l);

    items[length] = item;
    List_setLength(l, length + 1);

    return;
}
