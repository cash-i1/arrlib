#include <stdio.h>
#include <string.h>

#include "../arrlib.h"

// == test stuff ==
#define fail 1
#define ok 0

#define expect(_cond) if (!(_cond)) { \
    printf("expect: %s failed\n", #_cond); \
    return fail; \
}

#define run_test(_func, _inc_if_ok, _inc_if_fail) do { \
    if (_func() == ok) { \
        printf("ok:     %s()\n", #_func); \
        (_inc_if_ok)++; \
    } else { \
        printf("fail:   %s()\n", #_func); \
        (_inc_if_fail)++; \
    } \
} while (0)

// == tests ==
int test_init() {
    int* arr = arr_init(int, 10);
    expect(arr_cap(arr) == 10);
    expect(arr_count(arr) == 0);
    return ok;
}

int test_init_many() {
    int* array = arr_init_many(
        int, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    );
    expect(arr_cap(array) == 10);
    expect(arr_count(array) == 10);
    return ok;
}

int test_push() {
    int* arr = arr_init(int, 1);
    arr_push(arr, 12345);
    expect(arr_count(arr) == 1);
    expect(arr[0] == 12345);
    return ok;
}

int test_push_many() {
    int* arr = arr_init(int, 1);
    arr_push_many(arr, 1, 2, 3, 4, 5);
    expect(arr_count(arr) == 5);
    expect(arr[4] == 5);
    return ok;
}

int test_pop() {
    int* arr = arr_init_many(int, 10, 1, 2, 3);
    arr_pop(arr);
    arr_pop(arr);
    arr_pop(arr);
    expect(arr_count(arr) == 0)
    return ok;
}

int test_reset() {
    int* arr = arr_init_many(int, 10, 1, 2, 3);
    arr_reset(arr);
    expect(arr_count(arr) == 0);
    return ok;
}

int test_count() {
    int* arr = arr_init_many(int, 10, 1, 2, 3, 4, 5);
    expect(arr_count(arr) == 5);
    return ok;
}

int test_cap() {
    int* arr = arr_init(int, 10);
    expect(arr_cap(arr) == 10);
    return ok;
}

int test_struct() {
    typedef struct {
        int x, y, z;
    } some_struct;

    some_struct* arr = arr_init(some_struct, 10);
    arr_push_struct(arr, (some_struct){ 1, 2, 3 });
    arr_push_struct(arr, (some_struct){ 4, 5, 6 });
    arr_push_struct(arr, (some_struct){ 7, 8, 9 });

    expect(arr_count(arr) == 3);
    expect(arr[0].x == 1 && arr[0].y == 2 && arr[0].z == 3);
    expect(arr[1].x == 4 && arr[1].y == 5 && arr[1].z == 6);
    expect(arr[2].x == 7 && arr[2].y == 8 && arr[2].z == 9);

    return ok;
}

// TODO: this will always fail. there needs to be special functions for cstrs
int test_cstr() {
    char** arr = arr_init(char*, 10);
    arr_push(arr, "string1");
    arr_push(arr, "string2");
    arr_push(arr, "string3");

    expect(arr_count(arr) == 3);
    expect(strcmp(arr[0], "string1"));
    expect(strcmp(arr[1], "string2"));
    expect(strcmp(arr[2], "string3"));

    return ok;
}

int test_char() {
    char* arr = arr_init(char*, 10);
    arr_push(arr, 'a');
    arr_push(arr, 'b');
    arr_push(arr, 'c');

    expect(arr_count(arr) == 3);
    expect(arr[0] == 'a');
    expect(arr[1] == 'b');
    expect(arr[2] == 'c');

    return ok;
}

// == run tests ==
int main() {
    int amt_ok = 0;
    int amt_fail = 0;

    run_test(test_init, amt_ok, amt_fail);
    run_test(test_init_many, amt_ok, amt_fail);
    run_test(test_push, amt_ok, amt_fail);
    run_test(test_push_many, amt_ok, amt_fail);
    run_test(test_pop, amt_ok, amt_fail);
    run_test(test_reset, amt_ok, amt_fail);
    run_test(test_count, amt_ok, amt_fail);
    run_test(test_cap, amt_ok, amt_fail);
    run_test(test_struct, amt_ok, amt_fail);
    // TODO: this test is disabled. see hte comment on test_cstr
    // run_test(test_cstr, amt_ok, amt_fail);
    run_test(test_char, amt_ok, amt_fail);

    int total = amt_ok + amt_fail;

    if (amt_fail != 0) {
        printf("%i/%i failed (%i ok, %i fail)\n",  amt_fail, total, amt_ok, amt_fail);
        exit(EXIT_FAILURE);
    } else {
        printf("all tests passed\n");
        exit(EXIT_SUCCESS);
    }
}
