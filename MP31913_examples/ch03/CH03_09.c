#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select,student_no=0;
    float Msum=0,Esum=0;
    
    struct student
    {
        char name[20];
        char no[10];
        struct student *next;
    };
    typedef struct student s_data;
    s_data *ptr;        /* 存取指標 */
    s_data *head;       /* 串列開頭指標 */
    s_data *new_data;   /* 新增元素所在位置指標 */

    head = (s_data*) malloc(sizeof(s_data));   /* 新增串列開頭元素 */
    ptr = head;    /* 設定存取指標位置 */
    ptr->next = NULL;    /* 目前無下個元素 */
    do
    {
        printf("(1)新增 (2)離開 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("姓名 學號 :");
            scanf("%s %s",ptr->name,ptr->no);
            new_data = (s_data*) malloc(sizeof(s_data));    /* 新增下一元素 */
            ptr->next = new_data;    /* 連接下一元素 */
            new_data->next = NULL;   /* 下一元素的next先設定為null */
            ptr = new_data;    /* 存取指標設定為新元素所在位置 */
        }
    } while (select != 2);
    
    ptr->next = head;    /* 設定存取指標從頭開始 */

    putchar('\n');
    ptr=head;
    do
    {
        printf("姓名：%s\t學號:%s\n", 
        ptr->name,ptr->no);
        ptr = ptr ->next;    /* 將head移往下一元素 */
    } while(ptr->next!= head);
    printf("---------------------------------------------------------\n");
    
    system("pause");
    return 0;
}

