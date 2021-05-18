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

        printf("\n//////////////���� ��� ����//////////////\n");
        printf("00. ����\t\t");
        printf("01. ���� �߰�\n");
        printf("02. �߰��� ���� ǥ��\t");
        printf("03. ���� ���� ����\n");
        printf("04. ���� ����\t\t");
        printf("05. ��� ���� ����\n");
        printf("06. ������� ���\t");
        printf("07. ���� �˻�\n");
        printf("08. ���� ���� ����\t");
        printf("09. ���� ���� �ҷ�����\n");

        printf("\n��ȣ�� �Է��ϼ���.");
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
                printf("���� : �ٽ� �Է��ϼ���!\n");
                return 1;
            }
        }
        // �ҹ���->�빮�� ��ȯ
        else if((c[0] >= 'a' && c[0] <= 'd') || c[0] == 'f') c[0] -=32;
        else{
            printf("���� : �ٽ� �Է��ϼ���!\n");
            return 1;
        }
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////
///////////////////// CRUD Operations ////////////////////////////////
//////////////////////////////////////////////////////////////////////

// ����/���� ����, ���Ǹ�, ����, ����
Node* createCourse(Node* course) // Node* course == Node* HEAD in main
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("���� ������ �����ϼ���. (���� : 1, ���� : 2)");
    printf("\n=> ");
    scanf("%d", &newNode->type);

    while(getchar() != '\n');
    printf("���� �̸��� �Է��ϼ���.");
    printf("\n=> ");
    //fgets(newNode->name, sizeof(newNode->name), stdin);
    scanf("%[^\n]s", newNode->name);

    printf("���� ������ �Է��ϼ���.");
    printf("\n=> ");
    scanf("%d", &newNode->credit);

    do{
        while(getchar() != '\n');
        printf("���� ������ �Է��ϼ���. (A+, B0 �� ���ڷ� �Է�)");
        printf("\n=> ");
        //fgets(newNode->grade, sizeof(newNode->grade), stdin);
        scanf("%2s%*s", newNode->grade);
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
    if(index == 0) {
        printf("��ҵǾ����ϴ�.\n");
        return course;
    }
    
    Node* curr = course;

    for(int i=0; i< index-1; i++)
        curr = curr -> next;

    while(1)
    {
        int num;

        printf("\n++++++++++++ ���� �޴� ++++++++++++\n");
        printf("0. ����\n");
        printf("1. ���� ����\n");
        printf("2. ���Ǹ�\n");
        printf("3. ����\n");
        printf("4. ����(����)\n");
        
        printf("\n������ ������ �ش��ϴ� ��ȣ�� �Է��ϼ���.");
        printf("\n=> ");
        scanf("%d", &num);

        switch(num)
        {   
            case 0:
                printf("����Ǿ����ϴ�.\n");
                return course;
            case 1:
                printf("���� ������ �����ϼ���. (���� : 1, ���� : 2)");
                printf("\n=> ");
                scanf("%d", &curr->type);
                printf("�����Ǿ����ϴ�.\n");
                break;
            case 2:
                while(getchar() != '\n');
                printf("���� �̸��� �Է��ϼ���.");
                printf("\n=> ");
                scanf("%[^\n]s", curr->name);
                printf("�����Ǿ����ϴ�.\n");
                break;
            case 3:
                 printf("���� ������ �Է��ϼ���.");
                 printf("\n=> ");
                 scanf("%d", &curr->credit);
                 printf("�����Ǿ����ϴ�.\n");
                 break;
            case 4:
                do{
                    while(getchar() != '\n');
                    printf("���� ������ �Է��ϼ���. (A+, B0 �� ���ڷ� �Է�)?");
                    printf("\n=> ");
                    //fgets(curr->grade, sizeof(curr->grade), stdin);
                    scanf("%2s%*s", curr->grade);
                }while(convertGrade(curr->grade));
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