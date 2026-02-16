#include "List.h"

#include <stdbool.h>
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
    l->capacity = capacity;
    l->items = malloc(capacity * sizeof(void *));

    return l;
}

List List_createFromItems(void **items, size_t itemsLength) {
    List l = malloc(sizeof(struct List));
    size_t length = itemsLength;
    size_t capacity = itemsLength * 2;

    l->length = length;
    l->capacity = capacity;
    l->items = malloc(capacity * sizeof(void *));

    for (size_t i = 0; i < length; i++) {
        l->items[i] = items[i];
    }

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

void *List_getItemAtIndex(List l, size_t index) {
    return (void *)List_getItems(l)[index];
}

void List_setItemAtIndex(List l, size_t index, void *item) {
    l->items[index] = item;

    return;
}

void List_doubleCapacity(List l) {
    size_t currentCapacity = List_getCapacity(l);
    void **currentItems = (void **)List_getItems(l);

    size_t newCapacity = currentCapacity * 2;
    void **newItems = realloc(currentItems, newCapacity * sizeof(void *));

    List_setCapacity(l, newCapacity);
    List_setItems(l, newItems);

    return;
}

void List_appendItem(List l, void *item) {
    if (List_isAtCapacity(l)) {
        List_doubleCapacity(l);
    }

    size_t length = List_getLength(l);

    List_setItemAtIndex(l, length, item);
    List_setLength(l, length + 1);

    return;
}

bool List_isAtCapacity(List l) {
    size_t length = List_getLength(l);
    size_t capacity = List_getCapacity(l);

    return length == capacity;
}
