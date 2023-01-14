#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"

int main() {
    char ch = 'i';
    string s;

    s = CharToString(ch);
    printf("%c character turn to string: %s\n", ch, s);
    assert(strcmp(s, "i") == 0);
}