#include <stdio.h>
#include <stdlib.h>

int main()
{
    int select;
    
    struct student
    {
        char name[20];
        int Math;
        int Eng;
        char no[10];
        struct student *rlink;
        struct student *llink;
    };
    typedef struct student s_data;
    s_data *ptr;        /* 存取指標 */
    s_data *head;       /* 串列開頭指標 */
    s_data *new_data;   /* 新增元素所在位置指標 */

    head = (s_data*) malloc(sizeof(s_data)); 
    head->llink=NULL;
    head->rlink=NULL;
    ptr = head;   /* 設定存取指標開始位置  */
    do
    {
        printf("(1)新增 (2)離開 =>");
        scanf("%d", &select);
        if (select != 2)
        {
            printf("姓名 學號 數學成績 英文成績:");
            new_data = (s_data*) malloc(sizeof(s_data));    /* 新增下一元素 */
            scanf("%s %s %d %d",new_data->name,new_data->no,&new_data->Math,&new_data->Eng); 
            /*輸入節點結構中的資料 */
            ptr->rlink=new_data;
            new_data->rlink = NULL;   /* 下一元素的next先設定為null */
            new_data->llink=ptr;   /* 存取指標設定為新元素所在位置 */
            ptr=new_data;
        }
    } while (select != 2);

    ptr = head->rlink;    /* 設定存取指標從串列首的右指標欄所指節點開始 */
    putchar('\n');
    
    while (ptr!= NULL)
    {
     printf("姓名：%s\t學號:%s\t數學成績:%d\t英文成績:%d\n", ptr->name,ptr->no,ptr->Math,ptr->Eng);    
     ptr = ptr ->rlink;    /* 將ptr移往右邊下一元素 */   
     }
        
    system("pause");
    return 0;
}

