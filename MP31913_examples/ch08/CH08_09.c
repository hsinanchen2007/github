#include <stdio.h>
#include <stdlib.h>

void merge(FILE *fp, FILE *fp1, FILE *fp2)
{  
	int n1,n2;/*宣告變數n1，n2暫存資料檔data1及data2內的元素值*/
	n1=getc(fp1);/*從fp1中捉一個元素進來，存在n1*/
	n2=getc(fp2);
	while(feof(fp1)==0 && feof(fp2)==0)/*判斷是否已到檔尾*/
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
		putc(n2,fp);/*把另一個資料檔內的資料全部放到fp裡*/
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
		while(feof(fp1))
		{  
			n1=getc(fp1);
			putc(n1,fp);
		}
	}	 
}

int main(void)
{  
	char n;
	FILE *fp=fopen("data.txt","w+");/*宣告、並開啟建立新檔主檔指標 fp*/
	FILE *fp1=fopen("data1.txt","r");/*宣告資料檔1指標 fp1*/
	FILE *fp2=fopen("data2.txt","r");/*宣告資料檔2指標 fp2*/
	FILE *f,*f1,*f2;
	if(fp==NULL)
		printf("開啟主檔失敗\n");
	else if(fp1==NULL)
		printf("開啟資料檔 1 失敗\n");/*開啟檔案成功時，指標會傳回FILE檔案*/
	else if(fp2==NULL)/*指標，開啟失敗則傳回NULL值*/
		printf("開啟資料檔 2 失敗\n");
	else
	{  
		printf("資料排序中......\n");
        merge(fp,fp1,fp2);
		printf("資料處理完成!!\n");
	}
	fclose(fp);	/*關閉檔案*/
	fclose(fp1);
	fclose(fp2);

	printf("data1.txt資料內容為：\n");
	f1=fopen("data1.txt","r");
	while(1)
	{  
		n=getc(f1);
		if(feof(f1)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("data2.txt資料內容為：\n");
	f2=fopen("data2.txt","r");
	while(1)
	{  
		n=getc(f2);
		if(feof(f2)) break;
			printf("[%c] ",n);
	}
	printf("\n");
	printf("排序後data.txt資料內容為：\n");
	f=fopen("data.txt","r");
	while(1)
	{  
		n=getc(f);
		if(feof(f)) break;
		printf("[%c] ",n);
	}
	printf("\n");
	printf("\n");
	fclose(f);	/*關閉檔案*/
	fclose(f1);
	fclose(f2);
	system("pause");
	return 0;
}
