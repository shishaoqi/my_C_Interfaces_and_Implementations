#include <stdio.h>
#include <assert.h>
#include "genlib.h"

int main() {
    bool t, f;

    t = TRUE;
    f = FALSE;

    printf("t = %d, f = %d\n", t, f);
    assert(t == 1);
    assert(f == 0);

    _Bool bt, bf;
    bt = 1;
    bf = 0 && bt;

    printf("bt = %d, bf = %d\n", bt, bf);
    assert(bt == TRUE);
    assert(bf == FALSE);   

    // bool is an alias for _Bool if you include stdbool.h.
    // Basically, including the stdbool.h header is an indication that your code is OK with the identifier bool being 'reserved',
}