#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum Datatype(INT, FLOAT);

void printf_address_generic(enum Datatype type, char* str, void* p)
{
    printf("%s = %p\n", str, p);
    switch (type) {
    case INT:
        printf("%d\n", *(int*)p);
        break;
    case FLOAT:
        printf("%.3f\n", *(float*)p);
        break;
    default:
        printf("...\n");
        break
    }
}

int main()
{   
    int i = 10;
    float f = 123.456f;

    print_address_generic("i's address is", &i);
    print_address_generic("f's address is", &f);

    return 0;
}
