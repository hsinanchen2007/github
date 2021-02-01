#include<stdio.h>
int main(void)
{  
  int month;    
  printf("請輸入月份: ");    
  scanf("%d",&month);    
  if(2<=month & month<=4) 
    printf("充滿生機的春天\n");    

  else if(5<=month & month<=7)         
    printf("熱力四射的夏季\n");        
     
  else if(month>=8 & month <=10)
    printf("落葉繽紛的秋季\n");    
    
  else if(month==1 |month>=11 & month <=12 )        
    printf("寒風刺骨的冬季\n");        
      
  else        
    printf("很抱歉沒有這個月份!!!");  
  system("pause");          
  return 0; 
}
