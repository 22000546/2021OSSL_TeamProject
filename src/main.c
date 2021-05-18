///////////////////////////////////////////////////////////////////////
///////////////////// 공동 편집 영역 //////////////////////////////////
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
                printf("프로그램을 종료합니다.\n");
                return 0;
            // CREATE
            case 1:
                head = createCourse(head);
                printf("추가되었습니다.\n");
                break;
            // READ
            case 2:
                if(empty(head)) 
                    printf("오류 : 추가된 강의가 없습니다!\n");

                else 
                    readCourse(head);
                break;
            // UPDATE
            case 3:
                if(empty(head)) 
                    printf("오류 : 수정할 강의가 없습니다!\n");
                else{
                    readCourse(head);
                    head = updateCourse(head, selectCourseNo(head));
                }
                break;
            // DELETE
            case 4:
                if(empty(head)) 
                    printf("오류 : 삭제할 강의가 없습니다!\n");
                else {
                    readCourse(head);
                    head = deleteCourse(head, selectCourseNo(head));
                    printf("삭제되었습니다.\n");
                }
                break;
            // DELETE ALL
            case 5:
                if(empty(head)) 
                    printf("오류 : 삭제할 강의가 없습니다!\n");
                else{
                    head = clear(head);
                    printf("모두 삭제되었습니다.\n");
                }
                break;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
            // CALCULATION
            case 6:
                if(empty(head)) 
                    printf("오류 : 추가된 강의가 없습니다!\n");
                else calculate(head);
                break;
            // SEARCH
            case 7:
                if(empty(head)) 
                    printf("오류 : 추가된 강의가 없습니다!\n");
                else search(head);
                break;
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
            // SAVE
            case 8:
            {
                if(empty(head)) {
                    printf("저장되었습니다. (데이터 없음)\n");
                    remove("sampleCourses.txt");
                }
                else
                {
                    FILE* fcourse = fopen("sampleCourses.txt", "wt");
                    if(fcourse == NULL)
                        printf("오류 : 저장에 실패했습니다!\n");

                    else{
                        saveData(fcourse, head);
                        printf("저장되었습니다.\n");
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
                    printf("오류 : 불러올 데이터가 없습니다!\n");
                
                else{
                    head = loadData(fcourse, head);
                    printf("데이터를 불러오는 데 성공했습니다.\n");
                }
                fclose(fcourse);
                break;
            }
        }
    }
}