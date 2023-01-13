#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"

/*
 * Constant: MaxDigits
 * -------------------
 * This constant must be larger than the maximum
 * number of digits that can appear in a number.
 */

#define MaxDigits 30

/* Private function prototypes */

static string CreateString(int len);
static void NullStr(string s, string func);


string Concat(string s1, string s2) {
    int s1Len, s2Len, newStrLen;
    string newStr, tmpStr;

    if (s1 == NULL || s2 == NULL) {
        Error("NULL string passed to Concat");
    }
    s1Len = StringLength(s1);
    s2Len = StringLength(s2);

    newStrLen = s1Len + s2Len;
    //newStr = (char *)GetBlock(newStrLen);
    newStr = CreateString(newStrLen);

    // strcpy(newStr, s1);
    // strcpy(newStr + s1Len, s2);
    // newStr[s1Len + s2Len] = '\0';

    //tmpStr = newStr;
    strcpy(newStr, s1);
    tmpStr = newStr + s1Len;
    strcpy(tmpStr, s2);
    //strcpy(tmpStr + s2Len, "\0");
    tmpStr[s2Len] = '\0';

    return newStr;
}

char IthChar(string s, int i) {
    char c;
    int length;

    NullStr(s, "IthChar");
    length = StringLength(s);
    if (i < 0 || i > length) {
        Error("Index outside of string range in IthChar");
    }

    c = s[i];

    return c;
}

string SubString(string s, int p1, int p2) {
    int strLen, subStrLen;
    string subStr, srcSubStr;

    NullStr(s, "SubString");
    strLen = StringLength(s);

    if (p1 < 0) {
        p1 = 0;
    }

    if (p2 >= strLen) {
        p2 = strLen - 1;
    }

    subStrLen = p2 - p1 + 1;
    if (subStrLen < 0) {
        subStrLen = 0;
    }

    // subStr = CreateString(subStrLen);
    // strncpy(subStr, s + p1, subStrLen);
    // subStr[subStrLen] = '\0';
    // return subStr;

    subStr = (char *)GetBlock(subStrLen + 1);
    srcSubStr = subStr;
    
    int i;
    for (i = p1; i <= p2; i++) {
        *subStr++ = s[i]; 
    }
    subStr[subStrLen] = '\0';

    return srcSubStr;
}

string CharToString(char ch) {
    string s;

    s = CreateString(1);
    s[0] = ch;
    s[1] = '\0';

    return s;
}

int StringLength(string s) {
    NullStr(s, "StringLength");
    size_t len = strlen(s);
    return (int)len;
}

string CopyString(string s) {
    string newStr;
    int len;

    NullStr(s, "CopyString");
    len = strlen(s);
    newStr = CreateString(len);
    strcpy(newStr, s);

    return newStr;
}

int FindChar(char ch, string text, int start) {
    int i, len;
    char c;
    string tmp;

    NullStr(text, "FindChar");
    len = strlen(text);
    if (start < 0) start = 0;
    if (start > (int)strlen(text)) return -1;

    tmp = text + start;
    for (i = 0; i < len; i++) {
        c = tmp[i];
        if (c == ch) {
            return start + i;
        }
    }

    return -1;
}

int FindString(string str, string text, int start) {
    char *cptr;
    if (str == NULL) Error("NULL pattern string in FindString");
    if (text == NULL) Error("NULL text string in FindString");

    if (start < 0)  start = 0;
    if (start > (int)strlen(text))  return -1;
    cptr = strstr(text + start, str);
    if (cptr == NULL)   return -1;
    return (int)(cptr - text);
}

string ConvertToLowerCase(string s) {
    string lower;
    int i;

    NullStr(s, "ConvertToLowerCase");
    lower = CreateString(strlen(s));
    for (i = 0; s[i] != '\0'; i++) {
        lower[i] = tolower(s[i]);
    }
    lower[i] = '\0';

    return lower;
}

string ConvertToUpperCase(string s) {
    string upper;
    int i;

    NullStr(s, "ConvertToLowerCase");
    upper = CreateString(strlen(s));
    for (i = 0; s[i] != '\0'; i++) {
        upper[i] = toupper(s[i]);
    }
    upper[i] = '\0';

    return upper;
}

string IntegerToString(int n) {
    char buffer[MaxDigits];

    sprintf(buffer, "%d", n);
    return CopyString(buffer);
}

int StringToInteger(string s) {
    int result;
    char dummy;

    if (s == NULL)
        Error("NULL string passed to StringToInteger");
    if (sscanf(s, " %d %c", &result, &dummy) != 1)
        Error("StringToInteger called on illegal number %s", s);

    return (result);
}

string RealToString(double d) {
    char buffer[MaxDigits];

    sprintf(buffer, "%G", d);  
    return (CopyString(buffer));
}

double StringToReal(string s) {
    double result;
    char dummy;

    if (s == NULL) Error("NULL string passed to StringToReal");
    if (sscanf(s, " %lg %c", &result, &dummy) != 1)
        Error("StringToReal called on illegal number %s", s);

    return (result);
}

/* Private functions */

/*
 * Function: CreateString
 * Usage: s = CreateString(len);
 * -----------------------------
 * This function dynamically allocates space for a string of
 * len characters, leaving room for the null character at the
 * end.
 */

static string CreateString(int len) {
    return ((string) GetBlock(len + 1));
}

static void NullStr(string s, string func) {
    if (s == NULL) Error("NULL string passed to %s", func);
}
