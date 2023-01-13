#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    string msg;
    msg = ReadLine(stdin);
    printf("the message from stand input: %s\n", msg);
}