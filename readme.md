# arrlib
simple **2 file** C library that provides a [dynamic array](https://en.wikipedia.org/wiki/Dynamic_array), similar to C++'s [std::vector](https://en.cppreference.com/w/cpp/container/vector.html) type.

## installation
copy `arrlib.c` and `arrlib.h` into your project.

## usage
```c
int main() {
    // create an array of int's with an initial capacity of 3
    int* numbers = arr_init(int, 3);

    // add `3` to the end of the array
    arr_push(numbers, 3);

    // add multiple numbers to the end of the array at once
    arr_push_many(numbers, 1, 4, 1, 5, 9);

    // use arr_count to get the length of the array
    for (int i = 0; i < arr_count(numbers); i++) {
        arr_push(numbers, i);
    }

    // remove the item at the end of the array
    arr_pop(numbers);

    // clear the array of all its items
    arr_reset(numbers);

    // free the array
    arr_free(numbers);

    // arrlib also works with structs
    typedef struct { float x, y; } vec2;

    // create a new array of structs
    vec2* positions = arr_init(vec2, 3);

    // use arr_push_struct to add a struct to the array
    arr_push_struct(positions, (vec2){ .x = 1, .y = 10 });

    // free the array
    arr_free(positions);
}

