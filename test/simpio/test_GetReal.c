#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    double num;
    printf("please input a Real: ");
    num = GetReal();
    printf("inputing a Real: %lf\n", num);
}