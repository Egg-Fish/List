#include "List.h"

#include <stddef.h>
#include <stdio.h>

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

// Property: l = List_createFromItems(items, n) -> length(l) == n

void property__List_createFromItems__sound(void **items, size_t n) {
    List l = List_createFromItems(items, n);

    if (l != NULL) {
        char message[1024];

        size_t length = List_getLength(l);

        snprintf(message, 1024,
                 "l = List_createFromItems(items, %zu) -> length(l) (%zu) == %zu", n,
                 length, n);

        TEST_ASSERT_EQUAL_UINT_MESSAGE(n, length, message);
    }

    List_destroy(l);
}

void test__List_createFromItems__sound__emptyArray(void) {
    void **items = {};
    size_t n = 0;

    property__List_createFromItems__sound(items, n);
}

void test__List_createFromItems__sound__charArray(void) {
    char items[] = {'h', 'e', 'l', 'l', 'o'};
    size_t n = 5;

    property__List_createFromItems__sound((void **)items, n);
}

// Property: items != NULL -> List_createFromItems(l, n) != NULL

void property__List_createFromItems__complete(void **items, size_t n) {
    List l = List_createFromItems(items, n);

    if (items != NULL) {
        const char *message = "items != NULL -> List_createFromItems(l, n) != NULL";

        TEST_ASSERT_NOT_NULL_MESSAGE(l, message);
    }

    List_destroy(l);
}

void test__List_createFromItems__complete__nullArray(void) {
    void **items = NULL;
    size_t n = 0;

    property__List_createFromItems__complete(items, n);
}

void test__List_createFromItems__complete__emptyArray(void) {
    void **items = {};
    size_t n = 0;

    property__List_createFromItems__complete(items, n);
}

// Property: List_appendItem(l, item) -> newLength = length + 1

void property__List_appendItem__sound(List l, void *item, size_t length) {
    List_appendItem(l, item);

    char message[1024];

    size_t newLength = List_getLength(l);

    snprintf(message, 1024,
             "List_appendItem(l, item) -> newLength (%zu) = length (%zu) + 1",
             newLength, length);

    TEST_ASSERT_EQUAL_UINT_MESSAGE(length + 1, newLength, message);
}

void test__List_appendItem__sound__oneItem(void) {
    List l = List_create();
    size_t length = List_getLength(l);

    void *item = (void *)67;

    property__List_appendItem__sound(l, item, length);

    List_destroy(l);
}

void test__List_appendItem__sound__eightItems(void) {
    List l = List_create();

    for (size_t i = 1; i <= 8; i++) {
        size_t length = List_getLength(l);
        void *item = (void *)i;

        property__List_appendItem__sound(l, item, length);
    }

    List_destroy(l);
}

void test__List_appendItem__sound__nineItems(void) {
    List l = List_create();

    for (size_t i = 1; i <= 9; i++) {
        size_t length = List_getLength(l);
        void *item = (void *)i;

        property__List_appendItem__sound(l, item, length);
    }

    List_destroy(l);
}

void test__List_appendItem__sound__sixteenItems(void) {
    List l = List_create();

    for (size_t i = 1; i <= 16; i++) {
        size_t length = List_getLength(l);
        void *item = (void *)i;

        property__List_appendItem__sound(l, item, length);
    }

    List_destroy(l);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test__List_createFromItems__sound__emptyArray);
    RUN_TEST(test__List_createFromItems__sound__charArray);

    RUN_TEST(test__List_createFromItems__complete__nullArray);
    RUN_TEST(test__List_createFromItems__complete__emptyArray);

    RUN_TEST(test__List_appendItem__sound__oneItem);
    RUN_TEST(test__List_appendItem__sound__eightItems);
    RUN_TEST(test__List_appendItem__sound__nineItems);
    RUN_TEST(test__List_appendItem__sound__sixteenItems);

    return UNITY_END();
}
