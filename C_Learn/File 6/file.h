#pragma once    // ��ó���⿡�� �ߺ��Ǿ� ó���ϴ°��� ����
// pragma�� vs�� �������̹Ƿ� ������ #ifndef �� ����� �ǰ�.

void print_1_student(Student);


typedef struct _student Student;
#pragma pack(push, 1)
struct _student {
    int nGrade;          // �г�
    int nClass;          // ��
    int nNumber;        // ��ȣ
    char szName[20];   // �̸�
    char szTel[15];     // ��ȭ��ȣ
    char szMajor[20];   // ����
};
#pragma pack(pop)