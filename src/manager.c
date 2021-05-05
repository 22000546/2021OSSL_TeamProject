#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "../inc/essential.h"
#include "../inc/manager.h"

void searchName(Node* course) {
  char search[20];
  int scnt = 0;

  printf("찾으시는 과목의 이름을 입력해주세요 : ");
  scanf("%s", search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(strstr(i->name, search)) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> 검색 결과입니다.\n");
    printf("\n번호   유형       이름         학점     평점\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(strstr(i->name, search)) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("찾으시는 결과가 없습니다.\n");
  }
}

void searchCredit(Node* course) {
  int search;
  int scnt = 0;

  printf("찾으시는 과목의 학점을 입력해주세요 : ");
  scanf("%d", &search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(i->credit == search) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> 검색 결과입니다.\n");
    printf("\n번호   유형       이름         학점     평점\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(i->credit == search) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("찾으시는 결과가 없습니다.\n");
  }
}

void searchGrade(Node* course) {
  char search[4];
  int scnt = 0;

  printf("찾으시는 과목의 평점을 입력해주세요 : ");
  scanf("%s", search);

  // 평점이 A+, A0, B+, B0, C+, C0, D+, D0, F 로 처리되었다고 가정
  for(Node* i = course; i != NULL; i = i->next) {
    if((i->grade[0] == search[0])&&(i->grade[1] == search[1])) {
      scnt ++;
    } else if((search[0] = 'F')&&(i->grade[0] = 'F')) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> 검색 결과입니다.\n");
    printf("\n번호   유형       이름         학점     평점\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(((i->grade[0] == search[0])&&(i->grade[1] == search[1]))||((search[0] = 'F')&&(i->grade[0] = 'F'))) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("찾으시는 결과가 없습니다.\n");
  }
}

#endif