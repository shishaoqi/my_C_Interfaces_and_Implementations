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
    return 0;
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
    line[n] = '\n';
    nline = (string)GetBlock(n+1);
    strcpy(nline, line);
    FreeBlock(line);
    return nline;
}