#include <stdio.h>
#define MAX_NUM 5

void change_value(int arr[])
{
    for (int i = 0; i < MAX_NUM; i++) {
        arr[i] = (i + 1) * 10;
    }
}



int main()
{
    int i;
    int int_arr[MAX_NUM] = { 1, 2, 3, 4, 5 };
    printf("before : \n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d", int_arr[i]);
        }
    
    change_value(int_arr);
    printf("\nafter : \n");

    for (i = 0; i < MAX_NUM; i++) {
        printf("%d", int_arr[1]);
    }

    return 0;
}
