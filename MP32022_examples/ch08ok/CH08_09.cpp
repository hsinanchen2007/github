/*
[示範]:直接合併排序法
       資料檔名：data1.txt,data2.txt，合併後檔案：data.txt
*/
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
void merge(ofstream& fp, ifstream& fp1, ifstream& fp2)
{  
    char n1,n2;
    char txt1[40];
    char txt2[40];
	fp1>>n1;
	fp2>>n2;
	while(fp1.eof()==0 && fp2.eof()==0)
	{  
		if (n1 <= n2)
		{  
            fp.put(n1);   
			fp1>>n1;/*接著讀下一筆 n1 的資料*/
		}
		else
		{  
            fp.put(n2);/*如果n2比較小，則把n2存到fp裡*/
			fp2>>n2;/*接著讀下一筆 n2的資料*/
		}
	}
	if(fp1.eof())/*如果其中一個資料檔已讀取完畢，經判斷後*/
	{ 
       /*把另一個資料檔內的資料全部放到fp裡*/
		while (!fp2.eof())
		{  
            fp2>>n2;
			fp.put(n2);
		}
	}
	else if (fp2.eof())
	{ 
		while(!fp1.eof())
		{             
            fp1>>n1;
			fp.put(n1);
		}
	}	 
}
int main(void)
{  
	char txt[40];;
	ofstream fp;
	ifstream fp1,fp2;
	ifstream f,f1,f2;
	fp.open("data.txt",ios::out);
	fp1.open("data1.txt",ios::in);
	fp2.open("data2.txt",ios::in);
	if(!fp.is_open())
		cout<<"開啟主檔失敗"<<endl;
	else if(!fp1.is_open())
		cout<<"開啟資料檔 1 失敗"<<endl;
	else if(!fp2.is_open())
		cout<<"開啟資料檔 2 失敗"<<endl;
	else
	{  
		cout<<"資料排序中......"<<endl;
        merge(fp,fp1,fp2);
		cout<<"資料處理完成!!"<<endl;
	}
	fp.close();
	fp1.close();
	fp2.close();
	cout<<"data1.txt資料內容為："<<endl;
	f1.open("data1.txt",ios::in);
	while(!f1.eof()) 
	{  
		f1>>txt;
		cout<<txt<<endl;
	}
	cout<<"data2.txt資料內容為："<<endl;
	f2.open("data2.txt",ios::in);
	while(!f2.eof())
	{  
		f2>>txt;
		cout<<txt<<endl;
	}
	cout<<"排序後data.txt資料內容為："<<endl;
	f.open("data.txt",ios::in);
	while(!f.eof())
	{  
		f>>txt;
		cout<<txt<<endl;
	}
	cout<<endl;
	f.close();
	f1.close();
	f2.close();
	return 0;
}
