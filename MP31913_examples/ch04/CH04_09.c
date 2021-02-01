#include <stdio.h>
#define EIGHT 8 /*定義最大堆疊容量*/
#define TRUE 1
#define FALSE 0
int queen[EIGHT];/*存放8個皇后之列位置*/
int number=0;/*計算總共有幾組解的總數*/
/*決定皇后存放的位置*/
/*輸出所需要的結果*/
void print_table()
{
     int x=0,y=0;
     number+=1;
     printf("\n");
     printf("八皇后問題的第%d組解\n\t",number);
     for(x=0;x<EIGHT;x++)
     {
        for(y=0;y<EIGHT;y++)
           if(x==queen[y])
              printf("<q>");
           else
              printf("<->");
        printf("\n\t");
     } 
     system("pause");    
}
void decide_position(int value) 
{
   int i=0;
   while(i<EIGHT)
   {
   /*是否受到攻擊的判斷式*/
      if(attack(i,value)!=1)
      {
         queen[value]=i;
         if(value==7)
            print_table();
         else
            decide_position(value+1);
      }
      i++;
   }    
}
/*測試在(row,col)上的皇后是否遭受攻擊
  若遭受攻擊則傳回值為1,否則傳回0*/
int attack(int row,int col)
{
    int i=0,atk=FALSE;
    int offset_row=0,offset_col=0;
    while((atk!=1)&&i<col)
    {
       offset_col=abs(i-col);
       offset_row=abs(queen[i]-row);
       /*判斷兩皇后是否在同一列在同一對角線上*/
       if((queen[i]==row)||(offset_row==offset_col))
          atk=TRUE;
       i++;
    }
    return atk;
}

/*主程式*/
int main(void)
{
    decide_position(0);      
    return 0; 
}
