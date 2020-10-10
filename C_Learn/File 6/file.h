#pragma once    // 전처리기에게 중복되어 처리하는것을 방지
// pragma는 vs에 종속적이므로 가능한 #ifndef 를 사용을 권고.

void print_1_student(Student);


typedef struct _student Student;
#pragma pack(push, 1)
struct _student {
    int nGrade;          // 학년
    int nClass;          // 반
    int nNumber;        // 번호
    char szName[20];   // 이름
    char szTel[15];     // 전화번호
    char szMajor[20];   // 전공
};
#pragma pack(pop)