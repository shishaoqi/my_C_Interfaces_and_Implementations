#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

int main() {
    string s;
    int n;

    printf("Please input -1:\n");
    s = GetLine();
    n = StringToInteger(s);
    assert(n == -1);

    printf("Please input 0:\n");
    s = GetLine();
    n = StringToInteger(s);
    assert(n == 0);

    printf("Please input 1:\n");
    s = GetLine();
    n = StringToInteger(s);
    assert(n == 1);

    printf("Please input 1000:\n");
    s = GetLine();
    n = StringToInteger(s);
    assert(n == 1000);
}