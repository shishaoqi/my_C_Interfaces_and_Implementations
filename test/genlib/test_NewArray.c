#include "genlib.h"

typedef struct {
    char *name;
    int age;
    char *country;
} humanT;

int main() {
    // 常规写法
    humanT *hmPtr;
    hmPtr = (humanT *) malloc(10 * sizeof(humanT));

    humanT *iteraterPtr;
    iteraterPtr = hmPtr;
    int i;
    for (i = 0; i < 10; i++) {
        humanT *tmpPtr = iteraterPtr;
        tmpPtr->name = "ZhangSan";
        tmpPtr->age = i;
        tmpPtr->country = "CN";
        iteraterPtr++;
    }

    iteraterPtr = hmPtr;
    for (i = 0; i < 10; i++) {
        humanT *tmpPtr = iteraterPtr;
        printf("hmPtr%d -- name: %s, age: %d, country: %s\n", i, tmpPtr->name, tmpPtr->age, tmpPtr->country);
        iteraterPtr++;
    }

    printf("---------------------------------------------\n");
    // 封装后的写法
    humanT *hmPtr2;
    hmPtr2 = NewArray(10, humanT);

    iteraterPtr = hmPtr2;
    for (i = 0; i < 10; i++) {
        humanT *tmpPtr = iteraterPtr;
        tmpPtr->name = "ZhangSan";
        tmpPtr->age = i;
        tmpPtr->country = "US";
        iteraterPtr++;
    }

    iteraterPtr = hmPtr2;
    for (i = 0; i < 10; i++) {
        humanT *tmpPtr = iteraterPtr;
        printf("hmPtr%d -- name: %s, age: %d, country: %s\n", i, tmpPtr->name, tmpPtr->age, tmpPtr->country);
        iteraterPtr++;
    }
}