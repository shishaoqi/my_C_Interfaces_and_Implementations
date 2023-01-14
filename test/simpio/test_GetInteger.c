#include <stdio.h>
#include <assert.h>
#include "genlib.h"
#include "simpio.h"

int main() {
    int num;
    printf("please input a integer: ");
    num = GetInteger();
    printf("inputing a number: %d\n", num);

    printf("input 100: ");
    num = GetInteger();
    assert(100 == num);

    printf("input 0:");
    num = GetInteger();
    assert(0 == num);
}