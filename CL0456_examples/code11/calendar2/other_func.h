#ifndef __OTHER_FUNCTION_H__
#define __OTHER_FUNCTION_H__

/*利用已知節氣推算其它節氣的函數，st的值以小寒節氣為0，大寒為1，其它節氣類推*/
double CalculateSolarTermsByExp(int year, int st);

double CalculateSolarTermsByFm(int year, int st);
double CalculateNewMoonByFm(int m);

#endif //__OTHER_FUNCTION_H__
