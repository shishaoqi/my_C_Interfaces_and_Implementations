#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"

int main() {
    double a = -1.0, b = 0.0, c = 1.0, d = -100000.005, e = 1000000.0000087654321;
    string s;

    s = RealToString(a);
    printf("Real %lf turn to string: %s\n", a, s);
    //assert(strcmp(s, "-1.0") == 0);

    s = RealToString(b);
    printf("Real %lf turn to string: %s\n", b, s);
    //assert(strcmp(s, "0.0") == 0);


    s = RealToString(c);
    printf("Real %lf turn to string: %s\n", c, s);
    //assert(strcmp(s, "1.0") == 0);


    s = RealToString(d);
    printf("Real %lf turn to string: %s\n", d, s);
    //assert(strcmp(s, "-100000.005") == 0);


    s = RealToString(e);
    printf("Real %lf turn to string: %s\n", e, s);
    //assert(strcmp(s, "1000000.000008") == 0);
}