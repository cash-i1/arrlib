#include <assert.h>
#include <stdlib.h>

typedef struct {
    // current max capacity of the array
    int cap; 
    // how many items are currently in the array
    int count;
} arr_header;

#define _arr_header(_arr) ((arr_header*)((char*)_arr - sizeof(arr_header)))
#define arr_init(_type, _init_cap) _arr_init(sizeof(_type), _init_cap)
#define arr_push(_arr, _item) (_arr_maybe_grow(_arr, 1, sizeof(typeof(arr[0]))), _arr[_arr_header(_arr)->count++] = _item)
#define arr_pop(_arr) (_arr_header(_arr)->count--)
#define arr_count(_arr) (_arr_header(_arr)->count)
#define arr_cap(_arr) (_arr_header(_arr)->cap)

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

        arr_header* new_header = (arr_header*)realloc(header, new_size);
        assert("realloc failed when trying to grow array" && new_header != NULL);

        new_header->cap = new_cap;
        return (char*)header + sizeof(arr_header);
    }

    return arr;
}
