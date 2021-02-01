#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enqueue(char*, int);    /* 置入佇列資料 */
int dequeue();           /* 取出佇列資料 */
int show();          /* 顯示佇列資料 */

struct student
{
    char name[20];
    int score;
    struct student *next;
};
typedef struct student s_data;

s_data *front =NULL;
s_data *rear = NULL;

int main()
{
    int select, score;
    char name[20];

    do
    {
        printf("(1)存入 (2)取出 (3)顯示 (4)離開 => ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                printf("姓名 成績：");
                scanf("%s %d", name, &score);
                enqueue(name, score);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
        }
    } while (select != 4);

    system("pause");
    return 0;
}


int enqueue(char* name, int score)
{
    s_data *new_data;

    new_data = (s_data*) malloc(sizeof(s_data));  /* 配置記憶體給新元素 */
    strcpy(new_data->name, name);   /* 設定新元素的資料 */
    new_data->score = score;
    if (rear == NULL)      /* 如果rear為NULL，表示這是第一個元素 */
        front = new_data;
    else
        rear->next = new_data;    /* 將新元素連接至佇列尾端 */

    rear = new_data;    /* 將rear指向新元素，這是新的佇列尾端 */
    new_data->next = NULL;    /* 新元素之後無其它元素 */
}


int dequeue()
{
    s_data *freeme;
    if (front == NULL)
        puts("佇列已空！");
    else
    {
        printf("姓名：%s\t成績：%d ....取出\n", front->name, front->score);
        freeme = front;    /* 設定將要釋放的元素指標 */
        front = front->next;    /* 將佇列前端移至下一個元素 */
        free(freeme);    /* 釋放所取出的元素之記憶體 */
    }
}

int show()
{
    s_data *ptr;
    ptr = front;
    if (ptr == NULL)
        puts("佇列已空！");
    else
    {
    puts("front -> rear");
        while (ptr != NULL)    /* 由front往rear走訪佇列 */
        {
            printf("姓名：%s\t成績：%d\n", ptr->name, ptr->score);
            ptr = ptr->next;
        }
    }
}
