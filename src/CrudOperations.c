#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "essential.h"

//////////////////////////////////////////////////////////////////////
///////////////////// Linked-list ADT ///////////////////////////////
//////////////////////////////////////////////////////////////////////
int size(Node* course)
{
    if(empty(course)) return 0;

    int count =0;
    for(Node* curr = course; curr != NULL; curr = curr->next)
        count++;

    return count;
}

int empty(Node* course)
{
    return (course == NULL) ? 1 : 0;
}

Node* last(Node* course)
{
    while(course->next != NULL)
        course = course->next;

    return course;
}

Node* clear(Node* course)
{
    if(empty(course)) return NULL;

    Node* curr = course;

    while( curr != NULL)
    {
        Node* prev = curr;
        curr = curr->next;
        free(prev);
    }
    return NULL;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
char* courseType(int type)
{
    return (type == 1) ? "전공" : "교양";
}

int selectCourseNo(Node* course)
{
    int num;
    do{
        // readCourse(course);

        printf("\n번호를 입력하세요. (취소: 0)");
        printf("\n=> ");
        scanf("%d", &num);

    }while(num > size(course) || num < 0);

    return num;
}
int printMenu(void)
{
    int num;

        printf("\n//////////////평점 평균 계산기//////////////\n");
        printf("00. 종료\t\t");
        printf("01. 강의 추가\n");
        printf("02. 추가한 강의 표시\t");
        printf("03. 강의 정보 수정\n");
        printf("04. 강의 삭제\t\t");
        printf("05. 모든 강의 삭제\n");
        printf("06. 평점평균 계산\t");
        printf("07. 강의 검색\n");
        printf("08. 강의 정보 저장\t");
        printf("09. 강의 정보 불러오기\n");

        printf("\n번호를 입력하세요.");
        printf("\n=> ");
        scanf("%d", &num);

    return num;
}

int convertGrade(char c[]) {
    while(1) {
        if((c[0] >= 'A' && c[0] <= 'D') || c[0] == 'F'){
            // A, B, C, D
            if(c[0] != 'F' && c[1] == '\0'){
                c[1] = '0';
                c[2] = '\0';
                break;
            }
            // A+, A0, B+, B0, C+, C0, D+, D0
            else if((c[0] != 'F' && c[1] == '+') || (c[0] != 'F' && c[1] == '0')) break;
            // F
            else if(c[0] == 'F' && c[1] == '\0') break;
            // A-, F0, ...
            else{
                printf("오류 : 다시 입력하세요!\n");
                return 1;
            }
        }
        // 소문자->대문자 변환
        else if((c[0] >= 'a' && c[0] <= 'd') || c[0] == 'f') c[0] -=32;
        else{
            printf("오류 : 다시 입력하세요!\n");
            return 1;
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
///////////////////// CRUD Operations ////////////////////////////////
//////////////////////////////////////////////////////////////////////

// 전공/교양 여부, 강의명, 학점, 평점
Node* createCourse(Node* course) // Node* course == Node* HEAD in main
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("강의 종류를 선택하세요. (전공 : 1, 교양 : 2)");
    printf("\n=> ");
    scanf("%d", &newNode->type);

    while(getchar() != '\n');
    printf("강의 이름을 입력하세요.");
    printf("\n=> ");
    //fgets(newNode->name, sizeof(newNode->name), stdin);
    scanf("%[^\n]s", newNode->name);

    printf("강의 학점을 입력하세요.");
    printf("\n=> ");
    scanf("%d", &newNode->credit);

    do{
        while(getchar() != '\n');
        printf("강의 성적을 입력하세요. (A+, B0 등 문자로 입력)");
        printf("\n=> ");
        //fgets(newNode->grade, sizeof(newNode->grade), stdin);
        scanf("%2s", newNode->grade);
    }while(convertGrade(newNode->grade));

    newNode->next = NULL;

    if(empty(course))
        return newNode;

    last(course)->next = newNode;
    return course;
}

void readCourse(Node* course)
{
    Node* curr = course;
    
    printf("\n번호   종류       이름         학점     평점\n");
    printf("===========================================\n");

    for(int i=0; curr != NULL; i++)
    {
        printf("%02d     %s       %-8s       %d       %s\n", i+1, courseType(curr->type), curr->name, curr->credit, curr->grade);
        curr = curr->next;
    }
}

Node* updateCourse(Node* course, int index)
{
    if(index == 0) {
        printf("취소되었습니다.\n");
        return course;
    }
    
    Node* curr = course;

    for(int i=0; i< index-1; i++)
        curr = curr -> next;

    while(1)
    {
        int num;

        printf("\n++++++++++++ 수정 메뉴 ++++++++++++\n");
        printf("0. 종료\n");
        printf("1. 강의 종류\n");
        printf("2. 강의명\n");
        printf("3. 학점\n");
        printf("4. 성적(평점)\n");
        
        printf("\n수정할 정보에 해당하는 번호를 입력하세요.");
        printf("\n=> ");
        scanf("%d", &num);

        switch(num)
        {   
            case 0:
                printf("종료되었습니다.\n");
                return course;
            case 1:
                printf("강의 종류를 선택하세요. (전공 : 1, 교양 : 2)");
                printf("\n=> ");
                scanf("%d", &curr->type);
                printf("수정되었습니다.\n");
                break;
            case 2:
                while(getchar() != '\n');
                printf("강의 이름을 입력하세요.");
                printf("\n=> ");
                scanf("%[^\n]s", curr->name);
                printf("수정되었습니다.\n");
                break;
            case 3:
                 printf("강의 학점을 입력하세요.");
                 printf("\n=> ");
                 scanf("%d", &curr->credit);
                 printf("수정되었습니다.\n");
                 break;
            case 4:
                do{
                    while(getchar() != '\n');
                    printf("강의 성적을 입력하세요. (A+, B0 등 문자로 입력)?");
                    printf("\n=> ");
                    //fgets(curr->grade, sizeof(curr->grade), stdin);
                    scanf("%2s", curr->grade);
                }while(convertGrade(curr->grade));
                printf("수정되었습니다.\n");
                break;
            default:
                printf("오류 : 다시 입력하세요!\n");
                break;
        }
    }
}

Node* deleteCourse(Node* course, int index)
{
    if(index == 0) {
        printf("취소되었습니다.\n");
        return course;
    }

    else if(index == 1) {
        Node* target = course;
        course = course->next;
        free(target);

        return course;
    }
    Node* prev = NULL;
    Node* curr = course;

    for(int i=0; i< index-1; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);

    return course;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////// FILE I/O ////////////////////////////////
//////////////////////////////////////////////////////////////////////
void saveData(FILE* fcourse, Node* course)
{
    Node* curr = course;
    int lineFeed = size(course) -1;

    while(curr != NULL)
    {
        fprintf(fcourse, "%d       %-8s       %d       %s", curr->type, curr->name, curr->credit, curr->grade);
        curr = curr->next;
        if(lineFeed)
        {
            fputs("\n\n", fcourse);
            lineFeed--;
        }
    }
}

Node* loadData(FILE* fcourse, Node* course)
{
    if(!empty(course)) course = clear(course);

    while(!feof(fcourse)){
        Node* newNode = (Node*)malloc(sizeof(Node));
        fscanf(fcourse, "%d %s %d %s", &newNode->type, newNode->name, &newNode->credit, newNode->grade);
        newNode->next = NULL;
        if(empty(course)) course = newNode;
        else last(course)->next = newNode;
    }
    return course;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////