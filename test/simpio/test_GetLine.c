#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    string s;
    printf("GetLine reads a line of text from standard input and returns the line as a string: ");
    s = GetLine();
    printf("get line: %s\n", s);
}