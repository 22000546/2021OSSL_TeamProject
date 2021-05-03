#include <stdio.h>
#include <stdlib.h>
#include "essential.h"

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

char* courseType(int type)
{
    return (type == 1) ? "전공" : "교양";
}

int selectCourseNo(Node* course)
{
    int num;
    do{
        readCourse(course);

        printf("\n편집할 목록의 번호? ");
        scanf("%d", &num);
    }while(num > size(course));

    return num;
}

// 전공/교양 여부, 강의명, 학점, 평점
Node* createCourse(Node* course) // Node* course == Node* HEAD in main
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("전공/교양 여부(전공 : 1, 교양 : 2)");
    scanf("%d", &newNode->type);

    while(getchar() != '\n');
    printf("추가할 과목 : ");
    //fgets(newNode->name, sizeof(newNode->name), stdin);
    scanf("%[^\n]s", newNode->name);

    printf("학점?");
    scanf("%d", &newNode->credit);

    while(getchar() != '\n');
    printf("평점?");
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
    
    for(int i=0; curr != NULL; i++)
    {
        printf("%d   %s       %s       %d       %s\n", i+1, courseType(curr->type), curr->name, curr->credit, curr->grade);
        curr = curr->next;
    }
}