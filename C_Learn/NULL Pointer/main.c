#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{   
    char szStr[] = "Hello World!!";
    char find_ch = 'r';
    char* p = NULL;

    printf("문자열 : \"%s\"안의 문자 '%c'가 ", szStr, find_ch );

    p = strchr(szStr, find_ch);
  
    if (p == NULL) {
        printf("없습니다!\n");
    }
    else {
        printf("있습니다!\n");
    }

    return 0;
}