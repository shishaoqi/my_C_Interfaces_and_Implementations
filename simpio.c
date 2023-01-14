#include <stdio.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"

/*
 * Constants:
 * ----------
 * InitialBufferSize -- Initial buffer size for ReadLine
 */

#define InitialBufferSize 120


int GetInteger(void) {
    string s;
    int n, count;
    char ch;

    while (TRUE) {
        s = GetLine();
        if (s == NULL) {
            Error("GetInteger: unexpected end of file");
        }
        count = sscanf(s, " %d %c", &n, &ch);
        switch (count) {
            case 1:
                FreeBlock(s);
                return n;
            case 2:
                printf("Unexpected character: %c\n", ch);
                break;
            case 3:
                printf("Please enter a integer\n");
                break;
        }
        FreeBlock(s);
        printf("Retry: ");
    }
}

long GetLong(void) {
    string line;
    long value;
    char dummy;

    while (TRUE) {
        line = GetLine();
        if (line == NULL) {
            Error("GetLong: unexpected end of file");
        }
        switch(sscanf(line, " %ld %c", &value, &dummy)) {
            case 1:
                FreeBlock(line);
                return value;
            case 2:
                printf("Unexpected character:'%c'\n", dummy);
                break;
            case 3:
                printf("Please enter a integer");
                break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}

double GetReal(void) {
    string line;
    double value;
    char dummy;

    while (TRUE) {
        line = GetLine();
        if (line == NULL) Error("GetReal: unexpected end of file");
        switch (sscanf(line, " %lf %c", &value, &dummy)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", dummy);
            break;
          default:
            printf("Please enter a real number\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}


string GetLine(void) {
    string input;
    input = ReadLine(stdin);
    return input;
}

string ReadLine(FILE *infile) {
    string line, nline;
    int n, size;
    char ch;

    n = 0;
    size = InitialBufferSize;
    line = (string)GetBlock(size+1);
    while ((ch = getc(infile)) != '\n' && ch != EOF) {
        if (n == size) {
            size = size * 2;
            nline = (string)GetBlock(size+1);
            strncpy(nline, line, n);
            FreeBlock(line);
            line = nline;
        }
        line[n++] = ch;
    }

    if (n == 0 && ch == EOF) {
        FreeBlock(line);
        return NULL;
    }
    line[n] = '\0';
    nline = (string)GetBlock(n+1);
    strcpy(nline, line);
    FreeBlock(line);
    return nline;
}