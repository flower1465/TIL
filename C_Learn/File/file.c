#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{   
    int c;

    c = fgetc(stdin);
    while (c != EOF) {
        fputc(c, stdout);
        c = fgetc(stdin);
    }

    return 0;
}
