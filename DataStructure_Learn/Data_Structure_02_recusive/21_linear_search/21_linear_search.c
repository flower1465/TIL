#define _CRT_SECURE_NO_WARNINGS
//#define _TYPE_OF_FUCTION_ 
#include <stdio.h>

int LSearch(int arr[], int idx, int target) {
    for (int i = 0; i < idx; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int LSearchRecursive(int arr[], int idx, int size, int target) {
    if (idx == size) {
        return -1;
    }
    else if (arr[idx] == target) {
        return idx;
    }
    return LSearchRecursive(arr, idx + 1, size, target);
}

int main(void)
{
    int arr[] = { 3, 5, 2, 4, 9 };
    int idx;
    int target;

    printf("탐색할 정수값을 입력하시오! 끝내고자 할 시 q를 입력하시오\n");
    while (scanf("%d", &target) == 1) {
#ifdef _TYPE_OF_FUCTION_
        idx = LSearch(arr, sizeof(arr) / sizeof(int), target);
#else
        idx = LSearchRecursive(arr, 0, sizeof(arr) / sizeof(int), target);
#endif
        if (idx == -1)  
            printf("탐색 실패 \n");
        else
            printf("타겟 저장 인덱스: %d \n", idx);
    }

    return 0;
}