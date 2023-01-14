#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

int main() {
    string s;
    double n;

    printf("Please input -1.0:\n");
    s = GetLine();
    n = StringToReal(s);
    assert(n == -1.0);

    printf("Please input 0.0:\n");
    s = GetLine();
    n = StringToReal(s);
    assert(n == 0.0);

    printf("Please input 1.01:\n");
    s = GetLine();
    n = StringToReal(s);
    assert(n == 1.01);

    printf("Please input 1000.0:\n");
    s = GetLine();
    n = StringToReal(s);
    assert(n == 1000.0);
}