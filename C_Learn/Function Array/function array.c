#include <stdio.h>
#include <string.h>

void print_str_1(char* szStr)
{
    int i;
    for (i = 0; i < strlen(szStr); i++) {
        putchar(*(szStr + i));
    }
}

void print_str_2(char szStr[])
{
    int i;
    for (i = 0; i < stlen(szStr); i++) {
        putchar(szStr[i]);
    }
}


int main()
{
    char szStr[] = "the is test!!";
    print_str_1(szStr);
    putchar('\n');
    print_str_2(szStr);

    return 0;
}
