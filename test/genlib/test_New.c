#include "genlib.h"
#include <assert.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *country;
} * humanTP; // 声明结构体指针

int main() {
    // 常规写法
    humanTP hm1;
    hm1 = (humanTP) malloc(sizeof *((humanTP) NULL));
    printf("hm1 sizeof *((humanTP) NULL): %lu\n", sizeof *((humanTP) NULL)); // 对比 sizeof(humanTP)
    //hm1 = (humanTP) malloc(sizeof(humanTP)); // 结构指针里的（所指向的）结构体空间大小，不能用此方式得到
    printf("hm1 sizeof(humanTP): %lu\n", sizeof(humanTP));
    hm1->name = "ZhangSan";
    hm1->age = 20;
    hm1->country = "CN";
    assert(strcmp(hm1->name, "ZhangSan") == 0);
    assert(hm1->age == 20);
    assert(strcmp(hm1->country, "CN") == 0);
    printf("hm1 -- name: %s, age: %d, country: %s\n", hm1->name, hm1->age, hm1->country);


    // 封装后的写法
    humanTP hm2;
    hm2 = New(humanTP);
    hm2->name = "LiSi";
    hm2->age = 22;
    hm2->country = "US";
    assert(strcmp(hm2->name, "LiSi") == 0);
    assert(hm2->age == 22);
    assert(strcmp(hm2->country, "US") == 0);
    printf("hm2 -- name: %s, age: %d, country: %s\n", hm2->name, hm2->age, hm2->country);
}