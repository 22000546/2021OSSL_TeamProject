// ���� ����Ʈ
#ifndef __ESSENTIAL_H__
#define __ESSENTIAL_H__
#include <stdio.h>

// type ��������(����:1, ����:2)
// name ���Ǹ�
// credit ������
// grade ����(���ĺ�) : A+, A0, B+, B0, C+, C0, D+, D0, F
typedef struct listNode{
    int type;    
    char name[20];
    int credit;
    char grade[3]; // [A] [+] [\0]
    struct listNode* next;
}Node;

//�߰��� ����� ������ ��ȯ�Ѵ�.
int size(Node* course);

//����� ����ִ��� Ȯ���Ѵ�.
//������� ���(�ƹ��͵� �߰����� ���� ���) 1��ȯ, �� �� 0 ��ȯ
int empty(Node* course);

//����� ������ ��带 ����Ų��.
Node* last(Node* course);

//��� ��带 �����Ѵ�.
//���α׷� �����, �Ǵ� ���� ������ ���
Node* clear(Node* course);

// ����ڿ��� �Է¹��� ���� ���� ��ȣ�� �´� ���ڿ��� ��ȯ�Ѵ�.
// 1 == ����
// 2 == ����
char* courseType(int type);

// ���Ǹ� �߰��Ѵ�.
Node* createCourse(Node* course);

// �߰�/������ ���Ǹ� ����Ѵ�.
void readCourse(Node* course);

// ���Ǹ� �����Ѵ�.
// ������ ������ ��ȣ�� �Է¹ް� ����ü ������� ������ �� �ֵ��� �����Ѵ�.
// ����/���� ����, ���Ǹ�, ������, ����
Node* updateCourse(Node* course, int index);

// ���Ǹ� �����Ѵ�.
// ������ ������ ��ȣ�� �Է¹ް� �ش� ��带 ���������Ѵ�.
Node* deleteCourse(Node* course, int index);

// �߰��� ���Ǹ� �����Ѵ�.
// �ؽ�Ʈ ���� course.txt
// ������ �� ���� ����ϵ���
void saveData(FILE* fcourse, Node* course);

// �ؽ�Ʈ ���Ͽ� ������ ���� ����� �ҷ��´�.
Node* loadData(FILE* fcourse, Node* course);

// ����ڿ��� �߰��� ���� ��� ��ȣ�� �Է¹޴´�.
int selectCourseNo(Node* course);

// �޴��� ����ϰ� �� ���ð��� ��ȯ�Ѵ�.
int printMenu(void);

// ����ڿ��� �Է¹��� ���ڿ��� ����(����) ǥ����� �´��� Ȯ���Ѵ�.
// ����(����) ǥ��� : A+, A0, B+, B0, C+, C0, D+, D0, F
// ���� :
// input : a output : A0
// input : A- output : (�ٽ� �Է¹޴´�)
// input : F0 output : (�ٽ� �Է¹޴´�)
int convertGrade(char c[]);
#endif