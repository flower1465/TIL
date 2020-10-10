#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define START_NUM 1

int main(int argc, char* argv[])
{   
    Student stu;
    char c;
    int stu_number;
    FILE* fp;

    if (argc <= 1) {
        fprintf(stderr, "argument error!!\nThis program requires 1 arguments!!!\n");
        fprintf(stderr, "uasge : %s file_name(r)\n", argv[0]);
        exif(-1);
    }

    if ((fp = fopen(argv[1], "rb")) != NULL) {
        do {
            printf("검색할 학생의 번호를 입력하세요.");
            if (scanf("%d", &stu_number) == 1) {
                fseek(fp, (stu_number - START_NUM) * sizeof(Student), SEEK_SET);
                if (fread(&stu, sizeof(Student), 1, fp) > 0 && stu.nNumber != 0)
                {
                    printf("%d %d %d %20s %15s %20s\n",
                        stu.nGrade, stu.nClass, stu.nNumber, stu.szName,
                        stu.szTel, stu.szMajor);
                }
                else {
                    printf("해당 정보 없음\n");
                }
            }
            printf("계속하겠습니까? (Y/N)");
            scanf(" %c", &c);
        } while (c == 'Y' || c == 'y');
        fclose(fp);
    }
    else {
        printf("file open error!!!\n");
        exit(-1);
    }
    return 0;
}
