#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "strlib.h"

int main() {
    string src, cpy;

    src = "source string";
    cpy = CopyString(src);

    printf("copy string: %s\n", cpy);
    assert(strcmp(src, cpy) == 0);

    CopyString(NULL);
}