#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "essential.h"

// 과목 이름으로 검색하는 함수
void searchName(Node* course); 

// 과목의 학점으로 검색하는 함수
void searchCredit(Node* course); 

// 평점으로 검색하는 함수
void searchGrade(Node* course); 

// 평점 계산과 관련된 연산을 진행하는 함수
void calculate();

// 원하는 계산 결과를 선택하여 반환하는 함수
int pickCalculationMode();

// 모든 입력된 데이터의 평점 평균을 계산하는 함수
float calculateTotalGrade(Node* course); 

// 입력된 데이터 중 전공 과목의 평점 평균을 계산하는 함수
float calculateMajorGrade(Node* course);

// 입력된 데이터 중 교양 과목의 평점 평균을 계산하는 함수
float calculateElectiveGrade(Node* course);

// 주어진 평점을 백분위 점수로 환산하는 함수
float convertToScore(float grade);
#endif