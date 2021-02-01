#include <stdio.h>
#include <stdlib.h>

int main( )
{
	int i,j,find,val=0,data[80]={0};
	for (i=0;i<80;i++)
		data[i]=(rand()%150+1);
	while (val!=-1)
	{  
		find=0;
		printf("請輸入搜尋鍵值(1-150)，輸入-1離開：");
		scanf("%d",&val);
		for (i=0;i<80;i++)
		{  
			if(data[i]==val)
			{  
				printf("在第 %3d個位置找到鍵值 [%3d]\n",i+1,data[i]);
				find++;
			}
		}
		if(find==0 && val !=-1)
			printf("######沒有找到 [%3d]######\n",val);
	}
	printf("資料內容：\n");
	for(i=0;i<10;i++)
	{ 
		for(j=0;j<8;j++)
			printf("%2d[%3d]  ",i*8+j+1,data[i*8+j]);
		printf("\n");
	}	
	system("pause");
	return 0;
}
