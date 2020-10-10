#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 128

int main(int argc, char* argv[])
{   
    FILE* read_fp, * write_fp;
        int line = 0;
    char buffer[MAX_LINE];

    if (argc <= 2) {
        fprintf(stderr, "argument error!!\nThis program requires 2 arguments!!\n");
        fprintf(stderr, "usage : %s file_name1(r) file_name2(w)\n", argv[0]);
        exit(-1);
    }

    read_fp = fopen(argv[1], "r");

    if (read_fp != NULL) {
        if (write_fp = fopen(argv[2], "w") == NULL) {
            printf("%s file open error!!!\n", argv[2]);
            exit(-1);
        }
        while (fgets(buffer, MAX_LINE, read_fp) != NULL) {
            fprintf(write_fp, "%3d %s", ++line, buffer);
        }
        fclose(read_fp);
        fclose(write_fp);
        printf("%s 파일에 저장 완료.\n", argv[2]);
    }

    else {
        printf("file open error!!!\n");
        exit(-1);
    }
    return 0;
    
}
