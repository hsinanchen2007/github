#include <stdio.h>
#include <stdlib.h>
#define EAST  MAZE[x][y+1]  /*定義東方的相對位置*/
#define WEST  MAZE[x][y-1]  /*定義西方的相對位置*/
#define SOUTH MAZE[x+1][y]	/*定義南方的相對位置*/
#define NORTH MAZE[x-1][y]	/*定義北方的相對位置*/
#define ExitX 8			/*定義出口的X座標在第八列*/
#define ExitY 10			/*定義出口的Y座標在第十行*/
struct list
{
	int x,y;
	struct list* next;
};
typedef struct list node;
typedef node* link;
int MAZE[10][12] = {2,1,1,1,1,0,0,0,1,1,1,1,	/*宣告迷宮陣列*/
		            1,0,0,0,1,1,1,1,1,1,1,1,
				    1,1,1,0,1,1,0,0,0,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,0,0,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,1,1,0,1,1,
					1,1,1,0,1,1,0,0,1,0,1,1,
					1,1,0,0,0,0,0,0,1,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,3};
link push(link stack,int x,int y)
{
	link newnode;
	newnode = (link)malloc(sizeof(node));
	if(!newnode)
	{
		printf("Error!記憶體配置失敗!\n");
		return NULL;
	}
	newnode->x=x;
	newnode->y=y;
	newnode->next=stack;
	stack=newnode;
    return stack;
}
link pop(link stack,int* x,int* y)
{
	link top;
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;
		*x=top->x;
		*y=top->y;
		free(top);
		return stack;
	}
	else
		*x=-1;
	return stack;
}
int chkExit(int x,int y,int ex,int ey)
{
	if(x==ex&&y==ey)
	{
		if(NORTH==1||SOUTH==1||WEST==1||EAST==2)
			return 1;
		if(NORTH==1||SOUTH==1||WEST==2||EAST==1)
			return 1;
		if(NORTH==1||SOUTH==2||WEST==1||EAST==1)
			return 1;
		if(NORTH==2||SOUTH==1||WEST==1||EAST==1)
			return 1;
    }
	return 0;
}

int main()
{
	int i,j,x,y;
	link path = NULL;
	x=1;	/*入口的X座標*/
	y=1;    /*入口的Y座標*/
	printf("[迷宮的地模擬圖(0表示牆,2表示入口,3表示出口]\n"); /*印出迷宮的路徑圖*/
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	while(x<=ExitX&&y<=ExitY)
	{
		MAZE[x][y]=6;
		if(NORTH==0)
		{
			x -= 1;
			path=push(path,x,y);
		}
		else if(SOUTH==0)
		{
			x+=1;
			path=push(path,x,y);
		}
		else if(WEST==0)
		{
			y-=1;
			path=push(path,x,y);
		}
		else if(EAST==0)
		{
			y+=1;
			path=push(path,x,y);
		}
		else if(chkExit(x,y,ExitX,ExitY)==1) /*檢查是否走到出口了*/
			break;
		else
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		}
	}
	printf("---------------------------\n");
	printf("[6表示老鼠走過的路線]\n"); /*印出老鼠走完迷宮後的路徑圖*/
	printf("---------------------------\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",MAZE[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
