#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "essential.h"

// 과목 이름으로 검색하는 함수
int searchName(Node* course); 

// 과목의 학점으로 검색하는 함수
int searchCredit(Node* course); 

// 평점으로 검색하는 함수
int searchGrade(Node* course); 

// 모든 입력된 데이터의 평점 평균을 계산하는 함수
float calculateTotalGrade(Node* course); 

// 입력된 데이터 중 전공 과목의 평점 평균을 계산하는 함수
float calculateMajorGrade(Node* course);

// 입력된 데이터 중 교양 과목의 평점 평균을 계산하는 함수
float calculateElectiveGrade(Node* course);
#endif