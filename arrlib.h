#include <assert.h>
#include <stdlib.h>

typedef struct {
    // current max capacity of the array
    int cap; 
    // how many items are currently in the array
    int count;
} arr_header;

#define arr_init(_type, _init_cap) _arr_init(sizeof(_type), _init_cap)

void* _arr_init(int item_size, int init_cap) {
    // allocate enough memory for the arr_header aswell as the items which will go 
    // after the arr_header in memeory
    void* ptr = malloc(sizeof(arr_header) + item_size * init_cap);
    assert("malloc failed when trying to initialize array" && ptr != NULL);

    // pointer to the array header
    arr_header* header = (arr_header*)ptr;

    // pointer to the start of the actual data
    char* data = ((char*)ptr + item_size);

    return data;
}
