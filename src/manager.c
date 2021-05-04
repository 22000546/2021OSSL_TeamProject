#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "../inc/essential.h"
#include "../inc/manager.h"

void searchName(Node* course) {
  char search[20];
  int scnt = 0;

  printf("찾으시는 이름을 입력해주세요 : ");
  scanf("%s", search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(strstr(i->name, search)) {
      scnt ++;
    }
  }

  if(scnt != 0) {
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

#endif