#include <stdio.h>
#include <string.h>
#include "strlib.h"

/**
 * @brief 
 * 加深 C语言对字符串的处理
 * 注意点：
 * 1. 在 C 语言中，字符串的结束是由空字符来标记的，空字符的内部编码是 0。在字符串和字符常量中用带转义符号的 \0 来表示
 * 2. 0 与 \0 有区别
 * 
 * @return int 
 */

void zeroExamine(char x);

int main() {
    char s1[7] = {'H', 'e', 'l', 'l', 'o', '0', '\0'};

    char s2[8] = "hello"; // 0~4，5之后的字符默认会被置为 0
    s2[5] = '0';
    s2[6] = '\0';

    printf("%s lenght is: %ld\n", s1, strlen(s1));
    int i = 0;
    for (i = 0; i < strlen(s1); i++) {
        zeroExamine(s1[i]);
        printf("character %d : %c = %d\n", i, s1[i], s1[i]);
    }

    printf("\n");
    for (i = 0; i < 7; i++) {
        zeroExamine(s1[i]);
        printf("character %d : %c = %d\n", i, s1[i], s1[i]);
    }
    printf("~~~~~end~~~~~\n\n");

    printf("%s lenght is: %ld\n", s2, strlen(s2));
    for (i = 0; i < strlen(s2); i++) {
        zeroExamine(s1[i]);
        printf("character %d : %c = %d\n", i, s2[i], s2[i]);
    }

    printf("\n");
    for (i = 0; i < 9; i++) { // 越界输出
        zeroExamine(s1[i]);
        if (i >= 8) printf("+ 越界输出\n");
        printf("character %d : %c = %d\n", i, s1[i], s2[i]);
    }

    printf("\ncopy string \n");
    char *cpy = (char *)GetBlock(7);
    cpy[5] = 'x';
    cpy[6] = 'x';
    strcpy(cpy, s1);
    printf("copy string %s lenght is: %ld\n", cpy, strlen(cpy));
    for (i = 0; i < 9; i++) {
        zeroExamine(cpy[i]);
        if (i >= 7) printf("+ 越界输出\n");
        printf("character %d : %c = %d\n", i, cpy[i], cpy[i]);
    }

    return 0;
}

void zeroExamine(char x) {
    if (x == '\0') {
        printf("空字符输出\n");
    }

    if (x == '0') {
        printf("数字 0 值输出\n");
    }
}