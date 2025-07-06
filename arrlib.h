#pragma once

#include <assert.h>
#include <stdlib.h>

typedef struct {
    // current max capacity of the array
    int cap; 
    // how many items are currently in the array
    int count;
} arr_header;

#define _arr_header(_arr) ((arr_header*)((char*)_arr - sizeof(arr_header)))

// create a new array with type _type and an initiaal capacity of _init_cap
#define arr_init(_type, _init_cap) _arr_init(sizeof(_type), _init_cap)
// add _item to _arr
#define arr_push(_arr, _item) (_arr_maybe_grow(_arr, 4, sizeof(typeof(arr[0]))), _arr[_arr_header(_arr)->count++] = _item)
// add n items to _arr
#define arr_push_many(_arr, ...) do { \
        typeof(arr[0]) _items[] = { __VA_ARGS__ }; \
        for (int _i = 0; _i < (int)sizeof(_items) / (int)sizeof(_items[0]); _i++) { \
             arr_push(_arr, _items[_i]); \
        } \
    } while (0) 
// remove the element at the end of _arr
#define arr_pop(_arr) _arr_header(_arr)->count > 0 ? (_arr_header(_arr)->count--) : 0
// clear _arr
#define arr_reset(_arr) (_arr_header(_arr)->count = 0)
// get how many elements are in _arr
#define arr_count(_arr) (_arr_header(_arr)->count)
// get the capacity of _arr
#define arr_cap(_arr) (_arr_header(_arr)->cap)
// free the array
#define arr_free(_arr) (free(_arr_header(_arr)))

void* _arr_init(int item_size, int init_cap);
void* _arr_maybe_grow(void* arr, int grow_by, int item_size);
