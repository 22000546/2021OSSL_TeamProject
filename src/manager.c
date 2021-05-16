#include "../inc/essential.h"
#include "../inc/manager.h"

void searchName(Node* course) {
  char search[20];
  int scnt = 0;

  printf("ã���ô� ������ �̸��� �Է����ּ��� : ");
  scanf("%s", search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(strstr(i->name, search)) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> �˻� ����Դϴ�.\n");
    printf("\n��ȣ   ����       �̸�         ����     ����\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(strstr(i->name, search)) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("ã���ô� ����� �����ϴ�.\n");
  }
}

void searchCredit(Node* course) {
  int search;
  int scnt = 0;

  printf("ã���ô� ������ ������ �Է����ּ��� : ");
  scanf("%d", &search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(i->credit == search) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> �˻� ����Դϴ�.\n");
    printf("\n��ȣ   ����       �̸�         ����     ����\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(i->credit == search) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("ã���ô� ����� �����ϴ�.\n");
  }
}

void searchGrade(Node* course) {
  char search[4];
  int scnt = 0;

  printf("ã���ô� ������ ������ �Է����ּ��� : ");
  scanf("%s", search);

  // ������ A+, A0, B+, B0, C+, C0, D+, D0, F �� ó���Ǿ��ٰ� ����
  for(Node* i = course; i != NULL; i = i->next) {
    if((i->grade[0] == search[0])&&(i->grade[1] == search[1])) {
      scnt ++;
    } else if((search[0] == 'F')&&(i->grade[0] == 'F')) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> �˻� ����Դϴ�.\n");
    printf("\n��ȣ   ����       �̸�         ����     ����\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(((i->grade[0] == search[0])&&(i->grade[1] == search[1]))||((search[0] == 'F')&&(i->grade[0] == 'F'))) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("ã���ô� ����� �����ϴ�.\n");
  }
}

void searchType(Node* course) {
  int search = 0;
  int scnt = 0;

  printf("=> ���� ���� (1), ���� ���� (2) �� �ϳ��� �Է����ּ���. : ");
  scanf("%d", &search);

  for(Node* i = course; i != NULL; i = i->next) {
    if(i->type == search) {
      scnt ++;
    }
  }

  if(scnt != 0) {
    printf("=> �˻� ����Դϴ�.\n");
    printf("\n��ȣ   ����       �̸�         ����     ����\n");
    printf("===========================================\n");
    int index = 1;
    for(Node* i = course; i != NULL; i = i->next) {
     if(i->type == search) {
        printf("%02d     %s       %-8s       %d       %s\n", index, courseType(i->type), i->name, i->credit, i->grade);
        index ++;
     }
    }
  } else {
    printf("ã���ô� ����� �����ϴ�.\n");
  }

}

void search(Node* course) {
  int searchMode = 0;
  printf("=> �˻� ��带 �������ּ���.\n");
  printf("=> �̸� (1), ���� (2), ���� (3), ����/���� (4)\n");
  printf("=> �������� �˻��Ͻðڽ��ϱ�? : ");
  scanf("%d", &searchMode);

  if(searchMode == 1)
    searchName(course);
  else if(searchMode == 2)
    searchCredit(course);
  else if(searchMode == 3)
    searchGrade(course);
  else if(searchMode == 4)
    searchType(course);
  else
    printf("�Է°��� �߸��Ǿ����ϴ�. �ٽ� �õ����ּ���.\n");

}

// ������� ����� ���� �Լ� ����

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

// ������� ����� ���� �Լ� ����

void printTotalGrade(Node* course) {
  printf("��ü ������� : ");
  printf("%.2f\n", calculateTotalGrade(course));
}

void printMajorGrade(Node* course) {
  printf("���� ������� : ");
  printf("%.2f\n", calculateMajorGrade(course));
}

void printElectiveGrade(Node* course) {
  printf("���� ������� : ");
  printf("%.2f\n", calculateElectiveGrade(course));
}

void printScore(Node* course) {
  float grade = calculateTotalGrade(course);
  float score = convertToScore(grade);
  printf("����� ȯ������ : ");
  printf("%.2f\n", score);
}

int pickCalculationMode() {
  int result;
  int major, elective, score;

  printf("=> ����� ���� ���� ����� �������ּ���.\n");
  printf("=> ���� ��������� �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:0) : ");
  scanf("%d", &major);
  printf("=> ���� ��������� �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:0) : ");
  scanf("%d", &elective);
  printf("=> ����� ȯ�� ������ �����Ͻðڽ��ϱ�? (��:1 / �ƴϿ�:0) : ");
  scanf("%d", &score);

  result = major + elective*10 + score*100;
  return result;
}

void calculate(Node* course) {
  int mode = pickCalculationMode();

  printf("\n=> ��� ����Դϴ�.\n\n");
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