#include "genlib.h"
#include <assert.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *country;
} humanT;

int main() {
    // 常规写法
    char *cp;
    cp = (char *)malloc(10);
    cp[8] = 'a';

    int i;
    for (i = 0; i < 10; i++) {
        printf("cp the address is: %p, value is: %c\n", &cp[i], cp[i]);
    }

    humanT *h1; 
    h1 = (void *)malloc(sizeof(humanT)); // sizeof(humanT) 获取数据结构的空间大小
    printf("h1 The size of humanT: %lu\n", sizeof(humanT));
    h1->name = "ZhangSan";
    h1->age = 20;
    h1->country = "CN";

    assert(strcmp(h1->name, "ZhangSan") == 0);
    assert(h1->age == 20);
    assert(strcmp(h1->country, "CN") == 0);
    printf("h1%d -- name: %s, age: %d, country: %s\n", i, h1->name, h1->age, h1->country);


    // 封装后的写法
    char *chPtr;
    chPtr = GetBlock(10);
    chPtr[8] = 'c';

    for (i = 0; i < 10; i++) {
        printf("chPtr the address is: %p, value is: %c\n", &chPtr[i], chPtr[i]);
    }

    humanT *h2; 
    h2 = GetBlock(sizeof(humanT));
    printf("h2 The size of humanT: %lu", sizeof(humanT));
    h2->name = "LiSi";
    h2->age = 22;
    h2->country = "US";

    assert(strcmp(h2->name, "LiSi") == 0);
    assert(h2->age == 22);
    assert(strcmp(h2->country, "US") == 0);
    printf("h2%d -- name: %s, age: %d, country: %s\n", i, h2->name, h2->age, h2->country);
}