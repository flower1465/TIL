#pragma once

typedef struct _student Student;

struct _student {
    int nGrade;          // 학년
    int nClass;          // 반
    int nNumber;        // 번호
    char szName[20];   // 이름
    char szTel[15];     // 전화번호
    char szMajor[20];   // 전공
};