#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    string msg;
    printf("ReadLine reads a line of text from the input file and returns the line as a string: ");
    msg = ReadLine(stdin);
    printf("the message from stand input: %s\n", msg);
}