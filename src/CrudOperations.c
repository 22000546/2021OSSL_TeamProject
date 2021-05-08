#include <stdio.h>
#include <stdlib.h>
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

        printf("\n///////평점 평균 계산기///////\n");
        printf("0. 종료\n");
        printf("1. 강의 추가하기\n");
        printf("2. 추가한 강의 보기\n");
        printf("3. 강의 수정하기\n");
        printf("4. 강의 삭제하기\n");
        printf("5. 강의 목록 저장하기\n");

        printf("10. 학점 계산하기\n");

        printf("\n번호를 입력하세요.");
        printf("\n=> ");
        scanf("%d", &num);

    return num;
}
//////////////////////////////////////////////////////////////////////
///////////////////// CRUD Functions /////////////////////////////////
//////////////////////////////////////////////////////////////////////
// 전공/교양 여부, 강의명, 학점, 평점
Node* createCourse(Node* course) // Node* course == Node* HEAD in main
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("전공/교양 여부? (전공 : 1, 교양 : 2)");
    printf("\n=> ");
    scanf("%d", &newNode->type);

    while(getchar() != '\n');
    printf("강의 이름(4글자까지)?");
    printf("\n=> ");
    //fgets(newNode->name, sizeof(newNode->name), stdin);
    scanf("%[^\n]s", newNode->name);

    printf("학점?");
    printf("\n=> ");
    scanf("%d", &newNode->credit);

    while(getchar() != '\n');
    printf("평점?");
    printf("\n=> ");
    fgets(newNode->grade, sizeof(newNode->grade), stdin);
    //scanf("%s", newNode->grade);

    newNode->next = NULL;

    if(empty(course))
        return newNode;

    last(course)->next = newNode;
    return course;
}

void readCourse(Node* course)
{
    Node* curr = course;
    
    printf("\n번호   유형       이름         학점     평점\n");
    printf("===========================================\n");

    for(int i=0; curr != NULL; i++)
    {
        printf("%02d     %s       %-8s       %d       %s\n", i+1, courseType(curr->type), curr->name, curr->credit, curr->grade);
        curr = curr->next;
    }
}

Node* updateCourse(Node* course, int index)
{
    Node* curr = course;

    for(int i=0; i< index-1; i++)
        curr = curr -> next;

    while(1)
    {
        int num;

        printf("\n++++++++++++ 수정 메뉴 ++++++++++++\n");
        printf("0. 종료\n");
        printf("1. 전공/교양 여부\n");
        printf("2. 강의명\n");
        printf("3. 학점\n");
        printf("4. 평점\n");
        
        printf("\n수정할 정보를 선택하세요. (번호 입력)");
        printf("\n=> ");
        scanf("%d", &num);

        switch(num)
        {   
            case 0:
                printf("종료되었습니다.\n");
                return course;
            case 1:
                printf("전공/교양 여부? (전공 : 1, 교양 : 2)");
                printf("\n=> ");
                scanf("%d", &curr->type);
                printf("수정되었습니다.\n");
                break;
            case 2:
                while(getchar() != '\n');
                printf("강의 이름(4글자까지)?");
                printf("\n=> ");
                scanf("%[^\n]s", curr->name);
                printf("수정되었습니다.\n");
                break;
            case 3:
                 printf("학점?");
                 printf("\n=> ");
                 scanf("%d", &curr->credit);
                 printf("수정되었습니다.\n");
                 break;
            case 4:
                while(getchar() != '\n');
                printf("평점?");
                printf("\n=> ");
                fgets(curr->grade, sizeof(curr->grade), stdin);
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

    while(curr != NULL)
    {
        fprintf(fcourse, "%s       %-8s       %d       %s", courseType(curr->type), curr->name, curr->credit, curr->grade);
        curr = curr->next;
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////