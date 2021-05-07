#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "essential.h"

// 과목 이름으로 검색하는 함수
void searchName(Node* course); 

// 과목의 학점으로 검색하는 함수
void searchCredit(Node* course); 

// 평점으로 검색하는 함수
void searchGrade(Node* course); 

// *****************************
//////// 계산과 관련된 함수 ////////
// *****************************

// *****************************
// 주어진 평점의 평균을 계산하는 함수
// *****************************

// 주어진 평점을 숫자로 계산하는 함수
float calculateGrade(char grade[]); 

// 모든 입력된 데이터의 평점 평균을 계산하는 함수
float calculateTotalGrade(Node* course); 

// 입력된 데이터 중 전공 과목의 평점 평균을 계산하는 함수
float calculateMajorGrade(Node* course);

// 입력된 데이터 중 교양 과목의 평점 평균을 계산하는 함수
float calculateElectiveGrade(Node* course);

// 계산된 평점을 백분위 점수로 환산하는 함수
float convertToScore(float grade);

// *****************************
// 계산한 평점평균을 출력하기 위한 함수
// *****************************

// 모든 입력된 데이터의 평점평균을 출력하는 함수
void printTotalGrade(Node* course);

void printMajorGrade(Node* course);

void printElectiveGrade(Node* course);

void printScore(Node* course);

// *****************************
// 계산 함수의 전체적인 실행을 위한 함수
// *****************************

// 원하는 계산 결과를 선택하여 반환하는 함수
int pickCalculationMode();

// 평점 계산과 관련된 연산을 진행하는 함수
void calculate(Node* course);

#endif