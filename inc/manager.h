#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "essential.h"

// �˻� �������̽� �Լ�
void search(Node* course);

// ���� �̸����� �˻��ϴ� �Լ�
void searchName(Node* course); 

// ������ �������� �˻��ϴ� �Լ�
void searchCredit(Node* course); 

// ������ ����/���� ���η� �˻��ϴ� �Լ�
void searchType(Node* course);

// �������� �˻��ϴ� �Լ�
void searchGrade(Node* course); 

// *****************************
//////// ���� ���õ� �Լ� ////////
// *****************************

// *****************************
// �־��� ������ ����� ����ϴ� �Լ�
// *****************************

// �־��� ������ ���ڷ� ����ϴ� �Լ�
float calculateGrade(char grade[]); 

// ��� �Էµ� �������� ���� ����� ����ϴ� �Լ�
float calculateTotalGrade(Node* course); 

// �Էµ� ������ �� ���� ������ ���� ����� ����ϴ� �Լ�
float calculateMajorGrade(Node* course);

// �Էµ� ������ �� ���� ������ ���� ����� ����ϴ� �Լ�
float calculateElectiveGrade(Node* course);

// ���� ������ ����� ������ ȯ���ϴ� �Լ�
float convertToScore(float grade);

// *****************************
// ����� ��������� ����ϱ� ���� �Լ�
// *****************************

// ��� �Էµ� �������� ��������� ����ϴ� �Լ�
void printTotalGrade(Node* course);

void printMajorGrade(Node* course);

void printElectiveGrade(Node* course);

void printScore(Node* course);

// *****************************
// ��� �Լ��� ��ü���� ������ ���� �Լ�
// *****************************

// ���ϴ� ��� ����� �����Ͽ� ��ȯ�ϴ� �Լ�
int pickCalculationMode();

// ���� ���� ���õ� ������ �����ϴ� �Լ�
void calculate(Node* course);

#endif