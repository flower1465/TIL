#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{   
    char s1[30] = "The,Little,Prince,test,test";

    char* ptr = strtok(s1, ",");

    while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, ",");
    }



    return 0;
}
