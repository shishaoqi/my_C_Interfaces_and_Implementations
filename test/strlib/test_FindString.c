#include <stdio.h>
#include "strlib.h"
#include "assert.h"

int main() {
    string s1, s2, s3, s4, content;
    int idx;

    content = "This function dynamically allocates space for a string of len characters, leaving room for the null character at the end.";

    s1 = "function";
    idx = FindString(s1, content, 0);
    assert(idx == 5);

    s2 = "for";
    idx = FindString(s2, content, 0);
    assert(idx == 42);

    s3 = "her";
    idx = FindString(s3, content, 0);
    assert(idx == -1);

    s4 = "his";
    idx = FindString(s4, content, 0);
    assert(idx == 1);
}