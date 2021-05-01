// 배열
#ifndef __ESSENTIAL_H__
#define __ESSENTIAL_H__
#include <stdio.h>

// 구조체 정의
// 과목명, 전공/교양 여부, 학점, 평점
typedef struct
{
    char name[20];
    int type;   
    int credit;
    double score[3];
}course;

// 과목 추가
int createCourse(course c);

// 추가/수정한 과목 출력
void readCourse(course c[]);

// 과목 수정
// 수정할 과목 입력받고 구조체 멤버별로 수정할 수 있도록 선택하여 수정하기.
void updateCourse(course c);

// 과목 삭제
// 과목명에 null 대입.
int deleteCourse(course c);

// 추가한 과목 저장
// 텍스트파일 course.txt
// 데이터 간 공백 출력
void saveData(FILE* fcourse, course c[], int count, int index);

// 텍스트 파일 불러오기
int loadData(course c[]);
#endif