#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    long num;
    printf("please input a long integer: ");
    num = GetLong();
    printf("inputing a long number: %ld\n", num);
}