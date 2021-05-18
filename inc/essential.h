// 연결 리스트
#ifndef __ESSENTIAL_H__
#define __ESSENTIAL_H__
#include <stdio.h>

// type 강의종류(전공:1, 교양:2)
// name 강의명
// credit 학점수
// grade 평점(알파벳) : A+, A0, B+, B0, C+, C0, D+, D0, F
typedef struct listNode{
    int type;    
    char name[20];
    int credit;
    char grade[3]; // [A] [+] [\0]
    struct listNode* next;
}Node;

//추가된 목록의 개수를 반환한다.
int size(Node* course);

//목록이 비어있는지 확인한다.
//비어있을 경우(아무것도 추가되지 않은 경우) 1반환, 그 외 0 반환
int empty(Node* course);

//목록의 마지막 노드를 가리킨다.
Node* last(Node* course);

//모든 노드를 삭제한다.
//프로그램 종료시, 또는 전부 삭제시 사용
Node* clear(Node* course);

// 사용자에게 입력받은 강의 유형 번호에 맞는 문자열을 반환한다.
// 1 == 전공
// 2 == 교양
char* courseType(int type);

// 강의를 추가한다.
Node* createCourse(Node* course);

// 추가/수정한 강의를 출력한다.
void readCourse(Node* course);

// 강의를 수정한다.
// 수정할 강의의 번호를 입력받고 구조체 멤버별로 수정할 수 있도록 선택한다.
// 전공/교양 여부, 강의명, 학점수, 평점
Node* updateCourse(Node* course, int index);

// 강의를 삭제한다.
// 삭제할 강의의 번호를 입력받고 해당 노드를 동적해제한다.
Node* deleteCourse(Node* course, int index);

// 추가한 강의를 저장한다.
// 텍스트 파일 course.txt
// 데이터 간 공백 출력하도록
void saveData(FILE* fcourse, Node* course);

// 텍스트 파일에 저장한 강의 목록을 불러온다.
Node* loadData(FILE* fcourse, Node* course);

// 사용자에게 추가된 강의 목록 번호를 입력받는다.
int selectCourseNo(Node* course);

// 메뉴를 출력하고 그 선택값을 반환한다.
int printMenu(void);

// 사용자에게 입력받은 문자열이 성적(평점) 표기법에 맞는지 확인한다.
// 성적(평점) 표기법 : A+, A0, B+, B0, C+, C0, D+, D0, F
// 예시 :
// input : a output : A0
// input : A- output : (다시 입력받는다)
// input : F0 output : (다시 입력받는다)
int convertGrade(char c[]);
#endif