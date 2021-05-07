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
    return (type == 1) ? "����" : "����";
}

int selectCourseNo(Node* course)
{
    int num;
    do{
        // readCourse(course);

        printf("\n��ȣ�� �Է��ϼ���. (���: 0)");
        printf("\n=> ");
        scanf("%d", &num);

    }while(num > size(course) || num < 0);

    return num;
}
int printMenu(void)
{
    int num;

        printf("\n///////���� ��� ����///////\n");
        printf("0. ����\n");
        printf("1. ��� �߰��ϱ�\n");
        printf("2. �߰��� ��� ����\n");
        printf("3. ��� �����ϱ�\n");
        printf("4. ��� �����ϱ�\n");

        printf("10. ���� ����ϱ�\n");

        printf("\n��ȣ�� �Է��ϼ���.");
        printf("\n=> ");
        scanf("%d", &num);

    return num;
}
//////////////////////////////////////////////////////////////////////
///////////////////// CRUD Functions /////////////////////////////////
//////////////////////////////////////////////////////////////////////
// ����/���� ����, ���Ǹ�, ����, ����
Node* createCourse(Node* course) // Node* course == Node* HEAD in main
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("����/���� ����? (���� : 1, ���� : 2)");
    printf("\n=> ");
    scanf("%d", &newNode->type);

    while(getchar() != '\n');
    printf("���� �̸�(4���ڱ���)?");
    printf("\n=> ");
    //fgets(newNode->name, sizeof(newNode->name), stdin);
    scanf("%[^\n]s", newNode->name);

    printf("����?");
    printf("\n=> ");
    scanf("%d", &newNode->credit);

    while(getchar() != '\n');
    printf("����?");
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
    
    printf("\n��ȣ   ����       �̸�         ����     ����\n");
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

        printf("\n//////////// ���� �޴� ////////////\n");
        printf("0. ����\n");
        printf("1. ����/���� ����\n");
        printf("2. ���Ǹ�\n");
        printf("3. ����\n");
        printf("4. ����\n");
        
        printf("\n������ ������ �����ϼ���. (��ȣ �Է�)");
        printf("\n=> ");
        scanf("%d", &num);

        switch(num)
        {   
            case 0:
                printf("����Ǿ����ϴ�.\n");
                return course;
            case 1:
                printf("����/���� ����? (���� : 1, ���� : 2)");
                printf("\n=> ");
                scanf("%d", &curr->type);
                printf("�����Ǿ����ϴ�.\n");
                break;
            case 2:
                while(getchar() != '\n');
                printf("���� �̸�(4���ڱ���)?");
                printf("\n=> ");
                scanf("%[^\n]s", curr->name);
                printf("�����Ǿ����ϴ�.\n");
                break;
            case 3:
                 printf("����?");
                 printf("\n=> ");
                 scanf("%d", &curr->credit);
                 printf("�����Ǿ����ϴ�.\n");
                 break;
            case 4:
                while(getchar() != '\n');
                printf("����?");
                printf("\n=> ");
                fgets(curr->grade, sizeof(curr->grade), stdin);
                printf("�����Ǿ����ϴ�.\n");
                break;
            default:
                printf("���� : �ٽ� �Է��ϼ���!\n");
                break;
        }
    }
}

Node* deleteCourse(Node* course, int index)
{
    if(index == 0) {
        printf("��ҵǾ����ϴ�.\n");
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