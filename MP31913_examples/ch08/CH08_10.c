#include <stdio.h>
#include <stdlib.h>

void merge (FILE *,FILE *,FILE *);/*宣告合併排序副程式*/
void me (FILE *,FILE *,FILE *,FILE *);/*宣告分割檔案副程式*/
void bubble(FILE *,int);/*已分割檔案中，以氣泡排序法進行內部排序*/
void showdata(FILE *); /*印出檔案內容*/
int main(void)
{  
	char n;
	FILE *fp=fopen("datafile.txt","r");/*宣告檔案指標*/
	FILE *fp1=fopen("sortdata.txt","w+");
	FILE *ff1=fopen("sort1.txt","w+");
	FILE *ff2=fopen("sort2.txt","w+");

	if(fp==NULL)/*檔案是否開啟成功*/
		printf("開啟原資料檔失敗\n");
	else if(fp1==NULL)
       	printf("開啟合併後檔案失敗\n");
	else if(ff1==NULL)
        printf("開啟分割檔 1 失敗\n");
	else if(ff2==NULL)
        printf("開啟分割案 2 失敗\n");
	else
	{  
		printf("檔案分割中......\n");
        me(fp,fp1,ff1,ff2);
		printf("檔案排序中......\n");
		printf("資料處理完成!!\n");
	}

	rewind(fp); /*重設各檔案指標*/
	rewind(fp1);
	rewind(ff1);
	rewind(ff2);
    /*列印檔案內容*/
	printf("原始檔datafile.txt資料內容為：\n");
	showdata(fp);
	printf("\n分割檔sort1.txt資料內容為：\n");
	showdata(ff1);
	printf("\n分割檔sort2.txt資料內容為：\n");
	showdata(ff2);
	printf("\n排序後sortdata.txt資料內容為：\n");

	showdata(fp1);

	fclose(fp);/*關閉檔案*/
	fclose(fp1);
	fclose(ff1);
	fclose(ff2);
	system("pause");
	return 0;
}
void me(FILE *fp,FILE *fp1,FILE *ff1,FILE *ff2)
{  
	int n1=0,n2=0;
	char da1,da2;
	while(1)
	{                          
		da1=getc(fp);
		if(feof(fp)) break;
		n1++;/*計數，n1為datafile的總筆數*/
	}

	rewind(fp);
	for(n2=0;n2<(n1/2);n2++)
	{  
		da2=getc(fp);/*把一半的檔案*/
	    putc(da2,ff1);/*分割到ff1去*/
	}
	rewind(ff1);
    bubble(ff1,n2);/*分割完後呼叫bubble副程式進行排序*/

	while(1)
	{  
		da2=getc(fp);/*把其他的datafile檔案*/
	    if(feof(fp)) break;
			putc(da2,ff2);/*內容分割到ff2去*/
	}
	rewind(ff2);
	bubble(ff2,(n1/2));/*分割完後呼叫bubble副程式進行排序*/

	rewind(ff1);
	rewind(ff2);
	merge(fp1,ff1,ff2);/*呼叫合併排序副程式*/
}
void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	char n1,n2;	/*宣告變數n1，n2暫存資料檔data1及data2內的元素值*/
	n1=getc(fp1);/*從fp1中捉一個元素進來，存在n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)	/*判斷是否已到檔尾*/
	{  
		if (n1 <= n2)
		{  
			putc(n1,fp);/*如果n1比較小，則把n1存到fp裡*/
			n1=getc(fp1);/*接著讀下一筆 n1 的資料*/
		}
		else
		{  
			putc(n2,fp);/*如果n2比較小，則把n2存到fp裡*/
			n2=getc(fp2);/*接著讀下一筆 n2的資料*/
		}
	}
	if(feof(fp1))/*如果其中一個資料檔已讀取完畢，經判斷後*/
	{ 
		putc(n2,fp);/*把另一個資料檔內的資料全部放到 fp 裡*/
		while (1)
		{  
			n2=getc(fp2);
			if(feof(fp2)) break;
			putc(n2,fp);
		}
	}
	else if (feof(fp2))
	{ 
		putc(n1,fp);
		while (feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}
void bubble (FILE *ff,int size)
{
	int ii=0,j,i,tmp,flag;
	char n;
	char data[100]={0};
	for(i=0;i<size;i++)
	{  
		n=getc(ff);
		if(feof(ff)) break;
		data[i]=n;
		ii++;
	}
	for(i=size;i>0;i--)
	{  
		flag=0;/*flag用來判斷是否有執行交換的動作*/
		for (j=0;j<i;j++)
		{  
			if(data[j+1]<data[j])
			{  
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
				flag++;
			}/*如果有執行過交換，則flag不為0*/
		}
		if(flag==0)break;
	}
	rewind(ff);
	for(i=1;i<=size;i++)
		putc(data[i],ff);
}
void showdata (FILE *ff)
{   
	char n;
	while(1)
	{  
		n=getc(ff);
		if(feof(ff)) break;
			printf("[%c]",n);
	}
	printf("\n");
}
