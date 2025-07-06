#include <stdio.h>

#include "../arrlib.h"

// == test stuff ==
#define fail 1
#define ok 0

#define expect(_cond) if (!(_cond)) { return fail; }

#define run_test(_func, _inc_if_ok, _inc_if_fail) do { \
    if (_func() == ok) { \
        printf("ok:   %s()\n", #_func); \
        (_inc_if_ok)++; \
    } else { \
        printf("fail: %s()\n", #_func); \
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

// == run tests ==
int main() {
    int amt_ok = 0;
    int amt_fail = 0;

    run_test(test_init, amt_ok, amt_fail);

    int total = amt_ok + amt_fail;

    if (amt_fail != 0) {
        printf("%i/%i failed (%i ok, %i fail)\n",  amt_fail, total, amt_ok, amt_fail);
        exit(EXIT_FAILURE);
    } else {
        printf("all tests passed\n");
        exit(EXIT_SUCCESS);
    }
}
