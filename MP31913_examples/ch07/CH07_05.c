#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10/*定義佇列的最大容量	*/

int front=-1;/*指向佇列的前端*/
int rear=-1;/*指向佇列的後端*/

struct list/*圖形頂點結構宣告*/
{
   int x;/*頂點資料*/
   struct list *next;/*指向下一個頂點的指標*/
};
typedef struct list node;
typedef node *link;
struct GraphLink
{
   link first;
   link last;       
};

int run[9];/*用來記錄各頂點是否走訪過*/
int queue[MAXSIZE];
struct GraphLink Head[9];


void insert(struct GraphLink *temp,int x)
{
   link newNode;
   newNode=(link)malloc(sizeof(node));
   newNode->x=x;
   newNode->next=NULL;  
   if(temp->first==NULL)
   { 
      temp->first=newNode;
      temp->last=newNode;
   }
   else 
   {
	 temp->last->next=newNode;
	 temp->last=newNode;
   }
}
/*佇列資料的存入*/
void enqueue(int value)
{
   if(rear>=MAXSIZE) return;
   rear++;
   queue[rear]=value;
}
/*佇列資料的取出*/
int dequeue() 
{
   if(front==rear) return -1;
   front++;
   return queue[front];
}
/*廣度優先搜尋法*/
void bfs(int current)
{
   link tempnode; /*臨時的節點指標*/
   enqueue(current); /*將第一個頂點存入佇列*/
   run[current]=1; /*將走訪過的頂點設定為1*/
   printf("[%d]",current); /*印出該走訪過的頂點*/
   while(front!=rear) { /*判斷目前是否為空佇列*/
      current=dequeue(); /*將頂點從佇列中取出*/
      tempnode=Head[current].first; /*先記錄目前頂點的位置*/
      while(tempnode!=NULL)
      {
         if(run[tempnode->x]==0)
         {
            enqueue(tempnode->x);
            run[tempnode->x]=1; /*記錄已走訪過*/
            printf("[%d]",tempnode->x);
         }
         tempnode=tempnode->next;
      }
   }
} 
void print(struct GraphLink temp)
{
   link current=temp.first;
   while(current!=NULL)
   {
      printf("[%d]",current->x);
      current=current->next;
   }
   printf("\n");
}

int main()
{
/*圖形邊線陣列宣告*/
   int Data[20][2] =  
   { {1,2},{2,1},{1,5},{5,1},{2,4},{4,2},{2,3},{3,2},{3,4},{4,3},
   {5,3},{3,5},{4,5},{5,4}};
   int DataNum;			
   int i,j;				
   printf("圖形的鄰接串列內容：\n"); /*列印圖形的鄰接串列內容*/
   for( i=1 ; i<6 ; i++ )
   { /*共有八個頂點*/
      run[i]=0; /*設定所有頂點成尚未走訪過*/
      printf("頂點%d=>",i);
      Head[i].first=NULL;
      Head[i].last=NULL;                 
	  for( j=0 ; j<20 ;j++)
      {
	     if(Data[j][0]==i)
         { /*如果起點和串列首相等，則把頂點加入串列*/
	        DataNum = Data[j][1];          
	        insert(&Head[i],DataNum);
	     }
	   }
	      print(Head[i]);/*列印圖形的鄰接串列內容*/
    } 	
    printf("廣度優先走訪頂點：\n");/*列印廣度優先走訪的頂點*/
    bfs(1);
    printf("\n");
	system("pause");
	return 0;
}
