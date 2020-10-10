#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[])
{   
    FILE* fp;
    int c;

    if (argc <= 1) {
        printf("argument error!!\nThis program requires 2 arguments!!\n");
        exit(-1);
    }

    fp = fopen(argv[1], "w");
    if (fp != NULL) {
        while ((c = fgetc(stdin)) != EOF) {
            fputc(c, fp);
        }
        fclose(fp);
        printf("%s 파일에 저장 완료.\n", argv[1]);
    }
    else {
        printf("file open error!!!\n");
    }

    return 0;
}
