#include <stdio.h>
#include <assert.h>
#include "genlib.h"
#include "strlib.h"

int main() {
    string s = "abcdefg";
    char c;
    int idx = 4;

    c = IthChar(s, idx);
    printf("The index of %d in %s is %c\n", idx, s, c);
    assert(c == 'e');
}