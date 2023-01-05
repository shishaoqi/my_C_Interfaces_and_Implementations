#include <stdio.h>
#include "genlib.h"

int main() {
    bool t, f;

    t = TRUE;
    f = FALSE;

    printf("t = %d, f = %d\n", t, f);

    _Bool bt, bf;
    bt = 1;
    bf = 0 && bt;

    printf("bt = %d, bf = %d\n", bt, bf);   
}