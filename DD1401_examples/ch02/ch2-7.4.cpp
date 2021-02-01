#include <cstdlib>
#include <iostream>
using namespace std;
     int Sparse[4][3] = {{5, 0, 0}, {0, 0, -1}, {3, 0, 0}, {0, 9, 10}};
     int Compress[6][3];
class fun
{
  public:
    void Sparse_print(int m, int n);
    void Compress_process(int m, int n);
    void Compress_print(int m, int n);
};

int main(int argc, char *argv[])
{
     fun obj;    
     //兩個矩陣相加 
     cout<<"===稀疏矩陣之壓縮的表示法===";
     cout<<"\n";
     obj.Sparse_print(4,3);                      //輸出稀疏矩陣
     obj.Compress_process(4, 3);                //壓縮處理 
     obj.Compress_print(6, 3);                  //輸出壓縮結果 
     system("PAUSE");
     return(0);
}

//輸出稀疏矩陣
void fun::Sparse_print(int m, int n)
{
     cout<<"輸出稀疏矩陣：";
     cout<<"\n";                    
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<Sparse[i][j];
       cout<<"\n";
     }
}

//壓縮處理 
void fun::Compress_process(int m, int n)
{
   int i,j,k;
   k = 1;                              // 設定變數初值     
   Compress[0][0] = m;                 // 陣列sparse有m列  
   Compress[0][1] = n;                 // 陣列sparse有n行 
   Compress[0][2] = 5;                 // 陣列使用5個元素  
   for ( i = 0; i < m; i++ )           // 二維陣列的走訪   
      for ( j = 0; j < n; j++ )
         if ( Sparse[i][j] != 0 )      // 判斷是否為非0元素   
         {
            Compress[k][0] = i;    // 儲存列數         
            Compress[k][1] = j;    // 儲存行數         
            //儲存元素值
            Compress[k][2] = Sparse[i][j];
            k++;                   // 下一列           
         }
}

//輸出壓縮結果
void fun::Compress_print(int m, int n)
{
     cout<<"輸出壓縮結果：";
     cout<<"\n";            
     int i, j;
     for(i = 0; i < m; i++){
       for(j = 0; j < n; j++)
         cout<<"   "<<Compress[i][j];
       cout<<"\n";
     }
}
