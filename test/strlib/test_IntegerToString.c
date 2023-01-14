#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"

int main() {
    int a = -1, b = 0, c = 1, d = -10000000, e = 1000000;
    string s;

    s = IntegerToString(a);
    printf("Integer %d turn to string: %s\n", a, s);
    assert(strcmp(s, "-1") == 0);

    s = IntegerToString(b);
    printf("Integer %d turn to string: %s\n", b, s);
    assert(strcmp(s, "0") == 0);


    s = IntegerToString(c);
    printf("Integer %d turn to string: %s\n", c, s);
    assert(strcmp(s, "1") == 0);


    s = IntegerToString(d);
    printf("Integer %d turn to string: %s\n", d, s);
    assert(strcmp(s, "-10000000") == 0);


    s = IntegerToString(e);
    printf("Integer %d turn to string: %s\n", e, s);
    assert(strcmp(s, "1000000") == 0);
}