///////////////////////////////////////////////////////////////////////
///////////////////// ���� ���� ���� //////////////////////////////////
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "manager.h"
#include "essential.h"

int main(void)
{
    Node* head = NULL;
    int menu;

    while(1)
    {
        menu = printMenu();

        switch(menu)
        {

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
            // EXIT
            case 0:
                clear(head);
                return 0;
            // CREATE
            case 1:
                head = createCourse(head);
                printf("�߰��Ǿ����ϴ�.\n");
                break;
            // READ
            case 2:
                if(empty(head)) 
                    printf("���� : �߰��� ���ǰ� �����ϴ�!\n");

                else 
                    readCourse(head);
                break;
            // UPDATE
            case 3:
                if(empty(head)) 
                    printf("���� : ������ ���ǰ� �����ϴ�!\n");
                else{
                    readCourse(head);
                    head = updateCourse(head, selectCourseNo(head));
                }
                break;
            // DELETE
            case 4:
                if(empty(head)) 
                    printf("���� : ������ ���ǰ� �����ϴ�!\n");
                else {
                    readCourse(head);
                    head = deleteCourse(head, selectCourseNo(head));
                    printf("�����Ǿ����ϴ�.\n");
                }
                break;
            // DELETE ALL
            case 5:
                if(empty(head)) 
                    printf("���� : ������ ���ǰ� �����ϴ�!\n");
                else{
                    head = clear(head);
                    printf("��� �����Ǿ����ϴ�.\n");
                }
                break;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
            // CALCULATION
            case 6:
                calculate(head);
                break;
            // SEARCH
            case 7:
                //searchName(head);
                //searchCredit(head);
                //searchGrade(head);
                break;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
            // SAVE
            case 8:
            {
                if(empty(head)) {
                    printf("����Ǿ����ϴ�. (������ ����)\n");
                    remove("sampleCourses.txt");
                }
                else
                {
                    FILE* fcourse = fopen("sampleCourses.txt", "wt");
                    if(fcourse == NULL)
                        printf("���� : ���忡 �����߽��ϴ�!\n");

                    else{
                        saveData(fcourse, head);
                        printf("����Ǿ����ϴ�.\n");
                    }
                    fclose(fcourse);
                }
                break;
            }
            // LOAD
            case 9:
            {
                FILE* fcourse = fopen("sampleCourses.txt", "r");

                if(fcourse == NULL)
                    printf("���� : �ҷ��� �����Ͱ� �����ϴ�!\n");
                
                else{
                    head = loadData(fcourse, head);
                    printf("�����͸� �ҷ����� �� �����߽��ϴ�.\n");
                }
                fclose(fcourse);
                break;
            }
        }
    }
}