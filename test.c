#include <assert.h>
#include <stdio.h>
#include "arrlib.h"

int main() {
    int* arr = arr_init(int, 1);
    for (int i =0; i < 10; i++)
        arr_push(arr, i);
    assert(arr_count(arr) == 10);

    arr_pop(arr);
    arr_pop(arr);
    arr_pop(arr);
    arr_pop(arr);
    arr_pop(arr);
    assert(arr_count(arr) == 5);

    printf("count = %i\n", _arr_header(arr)->count);
    // arr_push_many(arr, 1, 2, 3);

    for (int i = 0; i < arr_count(arr); i++) {
        printf("%i/%i: %i\n", i, arr_cap(arr), arr[i]);
    }
}
