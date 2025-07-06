#include <stdio.h>
#include "arrlib.h"

int main() {
    // TODO: this does not compile, just example of what the api should look like
    int* arr = arr_init(int, 1);
    for (int i =0; i < 1000; i++)
        arr_push(arr, 1);
    arr_push(arr, 1);
    arr_push(arr, 1);
    arr_push(arr, 2);
    arr_push(arr, 5);
    arr_push(arr, 4);
    arr_push(arr, 1);
    arr_push(arr, 8);
    arr_push(arr, 1);
    arr_push(arr, 1);
    printf("count = %i\n", _arr_header(arr)->count);
    // arr_push_many(arr, 1, 2, 3);
    //
    // for (int i = 0; i < arr_len(arr); i++) {
    //     printf("%i: %i\n", i, arr[i]);
    // }
}
