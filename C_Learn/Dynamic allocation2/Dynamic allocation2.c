#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int nNum, i, sum = 0;

    printf("사용자로부터 입력받은 점수의 갯수를 입력하세요.\n");
    scanf("%d", &nNum);

    if (nNum <= 0) {
        printf("1개 이상의 입력을하여야 합니다!!\n");
        return -1;
    }

    printf("%d개의 정수를 입력해주세요.\n", nNum);
    p = (int*)malloc(sizeof(int) * nNum);
    if (p == NULL) {
        printf("동적할당 오류가 발생하였습니다.\n");
        return -2;
    }

    for (i = 0; i < nNum; i++) {
        scanf("%d", p+i);
    }

    for (i = 0; i < nNum; i++) {
        sum += *(p+i);
        printf("%d ", *(p + i));
    }
    printf(": SUM -> %d", sum);
    free(p);

    return 0;
}





/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p;
    int nNum, i, sum = 0;

    printf("사용자로부터 입력받은 점수의 갯수를 입력하세요.\n");
    scanf("%d", &nNum);

    printf("%d개의 정수를 입력해주세요.\n", nNum);
    p = (int*)malloc(sizeof(int) * nNum);
    for (i = 0; i < nNum; i++) {
        scanf("%d", p + i);
    }

    for (i = 0; i < nNum; i++) {
        sum += *(p + i);
        printf("%d ", *(p + i));
    }
    printf(": SUM -> %d", sum);
    free(p);

    return 0;
}
*/
