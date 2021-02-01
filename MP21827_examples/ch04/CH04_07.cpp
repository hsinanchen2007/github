#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define NUM1 4
#define NUM2 4
int process = 0;
int partition(int[], int, int);  
void mergeSort(int[], int, int[], int, int[]); 
void quick(int*,int,int,int);

int main(void) { 
   
    int list1[NUM1] = {16,25,39,27}; 
    int list2[NUM1] = {12,8,45,63}; 
    int list3[NUM1+NUM2] = {0}; 

    cout<<"排序前："; 
    cout<<"\nlist1[]："; 
    int i;
    
    for(i = 0; i < NUM1; i++) 
        cout<<list1[i]<<" ";
        
    cout<<"\nlist2[]："; 
    for(i = 0; i < NUM2; i++) { 
        //list2[i] = rand() % 100; 
        cout<<list2[i]<<" ";
    } 
      
    quick(list1,NUM1,0,NUM1-1);
    quick(list2,NUM2,0,NUM2-1);

    cout<<"\n排序後：";
    cout<<"\nlist1[]：";
    for(i = 0; i < NUM1; i++) 
        cout<<list1[i]<<" ";
    cout<<"\nlist2[]：";
    for(i = 0; i < NUM2; i++) 
        cout<<list2[i]<<" ";

    // 合併排序 
    mergeSort(list1, NUM1, list2, NUM2, list3); 

    cout<<"\n合併後："; 
    for(i = 0; i < NUM1+NUM2; i++) 
        cout<<list3[i]<<" ";
    cout<<endl;
        
	return 0; 
} 

void quick(int d[],int size,int lf,int rg)
{
	int tmp;
	int lf_idx;
	int rg_idx;
	int t;
    //1:第一筆鍵值為d[lf]
	if(lf<rg)
	{
		lf_idx=lf+1;
		rg_idx=rg;
    while(1) {
    	for(int i=lf+1;i<=rg;i++)
	//2:由左向右找出一個鍵值大於d[lf]者
		{
			if(d[i]>=d[lf])
			{
				lf_idx=i;
				break;
			}
			lf_idx++;
		}
		for(int j=rg;j>=lf+1;j--)
	//3:由右向左找出一個鍵值小於d[lf]者
		{
			if(d[j]<=d[lf]) 
			{
				rg_idx=j;
				break;
			}
			rg_idx--;
		}
		if(lf_idx<rg_idx)       
		 //4-1:若lf_idx<rg_idx
		{					     
			tmp = d[lf_idx];       
			d[lf_idx] = d[rg_idx];
			//則d[lf_idx]和d[rg_idx]互換
			d[rg_idx] = tmp;      //然後繼續排序 
        } else {
			break;    //否則跳出排序過程 
		} 
    }
		if(lf_idx>=rg_idx)      
		 //5-1:若lf_idx大於等於rg_idx
		{       //則將d[lf]和d[rg_idx]互換
			tmp = d[lf];
			d[lf] = d[rg_idx];
			d[rg_idx] = tmp;
                                      
			//5-2:並以rg_idx為基準點分成左右兩半
			quick(d,size,lf,rg_idx-1);
			//以遞迴方式分別為左右兩半進行排序
			quick(d,size,rg_idx+1,rg);
			//直至完成排序
		}
	}
}

void mergeSort(int list1[], int M, int list2[], 
               int N, int list3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while(i < M && j < N) 
	{ 
        if(list1[i] <= list2[j]) 
            list3[k++] = list1[i++]; 
        else 
            list3[k++] = list2[j++]; 
    } 

    while(i < M) 
        list3[k++] = list1[i++]; 
    while(j < N) 
        list3[k++] = list2[j++]; 
} 
