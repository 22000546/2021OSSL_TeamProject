#include "../inc/essential.h"
#include "../inc/manager.h"
#include <string.h>

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
    } else if((search[0] == 'F')&&(i->grade[0] == 'F')) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> 검색 결과입니다.\n");
    printf("\n번호   유형       이름         학점     평점\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(((i->grade[0] == search[0])&&(i->grade[1] == search[1]))||((search[0] == 'F')&&(i->grade[0] == 'F'))) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("찾으시는 결과가 없습니다.\n");
  }
}

void search(Node* course) {
  int searchMode = 0;
  printf("이름으로 검색하기 : 1\n");
  printf("학점으로 검색하기 : 2\n");
  printf("평점으로 검색하기 : 3\n");
  printf("무엇으로 검색하시겠습니까? : ");
  scanf("%d", &searchMode);

  if(searchMode == 1)
    searchName(course);
  else if(searchMode == 2)
    searchCredit(course);
  else if(searchMode == 3)
    searchGrade(course);
  else
    printf("입력값이 잘못되었습니다. 다시 시도해주세요.\n");

}

// 평점평균 계산을 위한 함수 구현

float calculateGrade(char grade[]) {
  float result = 0;
  if(grade[0] == 'A')
    result = 4;
  else if(grade[0] == 'B')
    result = 3;
  else if(grade[0] == 'C')
    result = 2;
  else if(grade[0] == 'D')
    result = 1;
  else if(grade[0] == 'F')
    result = 0;

  if(grade[1] == '+')
    result += 0.5;

  return result;
}

float calculateTotalGrade(Node* course) {
  float gradesum = 0, creditsum = 0;
  for(Node* i = course; i != NULL; i = i->next) {
    gradesum += i->credit * calculateGrade(i->grade);
    creditsum += i->credit;
  }
  float gradeaverage = gradesum / creditsum;
  return gradeaverage;
}

float calculateMajorGrade(Node* course) {
  float gradesum = 0, creditsum = 0;
  for(Node* i = course; i != NULL; i = i->next) {
    if(i->type == 1) {
      gradesum += i->credit * calculateGrade(i->grade);
      creditsum += i->credit;
    }
  }
  float gradeaverage = gradesum / creditsum;
  return gradeaverage;
}

float calculateElectiveGrade(Node* course) {
  float gradesum = 0, creditsum = 0;
  for(Node* i = course; i != NULL; i = i->next) {
    if(i->type == 2) {
      gradesum += i->credit * calculateGrade(i->grade);
      creditsum += i->credit;
    }
  }
  float gradeaverage = gradesum / creditsum;
  return gradeaverage;
}

float convertToScore(float grade) {
  float score = 60 + ((grade - 1) * 40 / 3.5);
  return score;
}

// 평점평균 출력을 위한 함수 구현

void printTotalGrade(Node* course) {
  printf("전체 평점평균 : ");
  printf("%.2f\n", calculateTotalGrade(course));
}

void printMajorGrade(Node* course) {
  printf("전공 평점평균 : ");
  printf("%.2f\n", calculateMajorGrade(course));
}

void printElectiveGrade(Node* course) {
  printf("교양 평점평균 : ");
  printf("%.2f\n", calculateElectiveGrade(course));
}

void printScore(Node* course) {
  float grade = calculateTotalGrade(course);
  float score = convertToScore(grade);
  printf("백분위 환산점수 : ");
  printf("%.2f\n", score);
}

int pickCalculationMode() {
  int result;
  int major, elective, score;

  printf("=> 결과를 보고 싶은 계산을 선택해주세요.\n");
  printf("=> 전공 평점평균을 선택하시겠습니까? (예:1 / 아니오:0) : ");
  scanf("%d", &major);
  printf("=> 교양 평점평균을 선택하시겠습니까? (예:1 / 아니오:0) : ");
  scanf("%d", &elective);
  printf("=> 백분위 환산 점수를 선택하시겠습니까? (예:1 / 아니오:0) : ");
  scanf("%d", &score);

  result = major + elective*10 + score*100;
  return result;
}

void calculate(Node* course) {
  int mode = pickCalculationMode();

  printf("\n=> 계산 결과입니다.\n\n");
  printTotalGrade(course);
  if(mode % 10 == 1)
    printMajorGrade(course);
  mode /= 10;
  if(mode % 10 == 1)
    printElectiveGrade(course);
  mode /= 10;
  if(mode % 10 == 1)
    printScore(course);
}