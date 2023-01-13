#include <stdio.h>
#include "genlib.h"
#include "strlib.h"

int main() {
    string s1, s2, newStr;
    s1 = "hello";
    s2 = "world";

    newStr = Concat(s1, s2);
    printf("new string: %s\n", newStr);

    int len = StringLength(newStr);
    printf("newStr length: %d\n", len);
}