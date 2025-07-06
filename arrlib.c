#include "arrlib.h"

void* _arr_init(int item_size, int init_cap) {
    // allocate enough memory for the arr_header aswell as the items which will go 
    // after the arr_header in memeory
    void* ptr = malloc(sizeof(arr_header) + (item_size * init_cap));
    assert("malloc failed when trying to initialize array" && ptr != NULL);

    // pointer to the array header
    arr_header* header = (arr_header*)ptr;
    header->cap = init_cap;
    header->count = 0;

    // pointer to the start of the actual data
    char* data = ((char*)ptr + sizeof(arr_header));

    return data;
}

void* _arr_maybe_grow(void* arr, int grow_by, int item_size) {
    assert("arr is NULL" && arr != NULL);
    arr_header* header = _arr_header(arr);

    // if the array is full
    if (header->count >= header->cap) {
        int new_cap = header->cap + grow_by;
        // in bytes
        int new_size = sizeof(arr_header) + (new_cap * item_size);

        // re allocate array with new size
        arr_header* new_header = (arr_header*)realloc(header, new_size);
        assert("realloc failed when trying to grow array" && new_header != NULL);

        // set the new array's cap and return a pointer to the data
        new_header->cap = new_cap;
        return (char*)header + sizeof(arr_header);
    }

    // nothing needs to happen so just return the arr back
    return arr;
}
